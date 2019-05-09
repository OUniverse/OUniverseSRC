//Copyright 2015-2019, All Rights Reserved.

#include "System/InputManager.h"
#include "Containers/Ticker.h"
#include "System/Command.h"
#include "System/CharKey.h"
#include "System/Major.h"

#include "System/DisplayManager.h"
#include "System/Paths.h"

#include "Util/FileFriend.h"

#include "CohtmlHUD.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlUTypeBinder.h"
#include "CohtmlFStringBinder.h"
#include "SCohtmlInputForward.h"


InputManager* InputManager::Create(UCohtmlHUD* InUi, TSharedPtr<class SCohtmlInputForward> InNativeUi, FString PathToReg)
{
	return new InputManager(InUi, InNativeUi, PathToReg);
}

InputManager::InputManager(UCohtmlHUD* InUi, TSharedPtr<class SCohtmlInputForward> InNativeUi, FString PathToReg)
{
	Ui = InUi;
	UiNative = InNativeUi;

	bRebindMode = false;
	bTypeMode = false;
	bPrimeTypeMode = false;

	FFileReader FileReader = FFileReader(PathToReg + REG_INPUTMANAGER);
	FileReader.ToJson();


	const TArray<TSharedPtr<FJsonValue>> *ArrDatri;

	FileReader.Json()->TryGetArrayField("command", ArrDatri);
	auto JArr = *ArrDatri;

	int Count;

	Count = JArr.Num();
	for (int i = 0; i < Count; i++)
	{
		FName CommandID = FName(*JArr[i]->AsObject()->GetStringField("i"));
		int KeyCode = JArr[i]->AsObject()->GetIntegerField("k");
		CommandC* NewCommand = new CommandC();
		NewCommand->ID = CommandID;
		CommandMap.insert({ CommandID, NewCommand });
		InputMap.insert({ KeyCode, NewCommand});


		NewCommand->BoundKeyCode = KeyCode;
	}

	FileReader.Json()->TryGetArrayField("primetype", ArrDatri);
	JArr = *ArrDatri;

	Count = JArr.Num();
	for (int i = 0; i < Count; i++)
	{
		CharKey* NewPTK = new CharKey(JArr[i]->AsObject()->GetStringField("i"));
		PTKeyMap.insert({ JArr[i]->AsObject()->GetIntegerField("k"), NewPTK } );
	}

}

void InputManager::BindUI()
{
	Ui->GetView()->BindCall("inputMNG.typeMode", cohtml::MakeHandler(this, &InputManager::TypeMode));
	Ui->GetView()->BindCall("inputMNG.typeModePrime", cohtml::MakeHandler(this, &InputManager::PrimeTypeMode));
}

CommandC* InputManager::GetCommand(FString CommandName)
{
	return CommandMap.find(*CommandName)->second;
}

void InputManager::BindCommandToKey(CommandC* CommandToBind, int32 KeyCode)
{
	if (CommandToBind->BoundKeyCode != -1)
	{
		InputMap.erase(KeyCode);
	}

	CommandToBind->BoundKeyCode = KeyCode;
}

void InputManager::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	int32 KeyCode = InKeyEvent.GetKeyCode();

	if (bPrimeTypeMode)
	{
			CharKey* PTK = PTKeyMap.find(KeyCode)->second;
			if (PTK != nullptr)
			{
				Ui->GetView()->TriggerEvent("inputMNG.onPTKey", PTK->ID);
			}
	}
	else if(bRebindMode)
	{
		//Special Logic incase we are rebinding the key;
		return;
	} else {

		UiNative->OnKeyDown(MyGeometry, InKeyEvent);

		//Fires off Mod generated custom keys via a second TMap
		std::map<int32, CommandC*>::iterator it;
		it = InputMap.find(KeyCode);

		if (it != InputMap.end())
		{

			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sending");
			it->second->Send(StrokeS(true));
		}
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(KeyCode));
	}
}

void InputManager::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{


	if (!bPrimeTypeMode && !bRebindMode)
	{
		int32 KeyCode = InKeyEvent.GetKeyCode();

		if (bRebindMode)
		{
			//Special Logic incase we are rebinding the key;
			return;
		}

		UiNative->OnKeyUp(MyGeometry, InKeyEvent);

		//Fires off Mod generated custom keys via a second TMap

		std::map <int32, CommandC*>::iterator it;
		it = InputMap.find(KeyCode);

		if (it != InputMap.end())
		{

			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sending");
			it->second->Send(StrokeS(false));
		}
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(KeyCode));
	}

}

void InputManager::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
	if (bPrimeTypeMode)
	{
		Ui->GetView()->TriggerEvent("inputMNG.onChar", FString().AppendChar(InCharacterEvent.GetCharacter()));
	}
	else {
		UiNative->OnKeyChar(MyGeometry, InCharacterEvent);
	}
	
}
void InputManager::OnMouseMove(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{

	UiNative->OnMouseMove(MyGeometry,MouseEvent);
}

void InputManager::OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	UiNative->OnMouseButtonDown(MyGeometry, MouseEvent);
}

void InputManager::OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	UiNative->OnMouseButtonUp(MyGeometry, MouseEvent);
}

void InputManager::OnMouseWheel(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	UiNative->OnMouseWheel(MyGeometry,MouseEvent);
}


void InputManager::PrimeTypeMode(int bEnabled)
{
	if (bEnabled == 1)
	{
		bPrimeTypeMode = true;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "PrimeType Mode Enabled");
	}
	else
	{
		bPrimeTypeMode = false;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "PrimeType Mode Canceled");
	}
}

void InputManager::TypeMode(int bEnabled)
{
	if (bEnabled == 1)
	{
		bTypeMode = true;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Type Mode Enabled");
	}
	else
	{
		bTypeMode = false;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Type Mode Canceled");
	}
}
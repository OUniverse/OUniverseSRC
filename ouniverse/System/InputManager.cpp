//Copyright 2015-2019, All Rights Reserved.

#include "System/InputManager.h"
#include "Containers/Ticker.h"
#include "System/Command.h"
#include "System/CharKey.h"
#include "System/Major.h"

#include "System/HudUE.h"
#include "System/Paths.h"

#include "Interface/File.h"
#include "Interface/Json.h"

#include "System/Glass.h"


#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlUTypeBinder.h"
#include "CohtmlFStringBinder.h"
#include "SCohtmlInputForward.h"



InputManager* InputManager::Create(DirS* InDirReg, GlassC* InGlass)
{
	return new InputManager(InDirReg, InGlass);
}

InputManager::InputManager(DirS* InDirReg, GlassC* InGlass)
{
	Glass_ = InGlass;
	
	bRebindMode = false;
	bTypeMode = false;
	bPrimeTypeMode = false;

	//FileReadS* FileReader = new FileReadS(TCHAR_TO_ANSI(*(PathToReg + REG_INPUTMANAGER)));

	//JsonS* InputReg = new JsonS(FileReader->AsChar());
	//InputReg[];

	CommandC* NewCommand = new CommandC();
	CommandArray.Init(Commands::COMMANDS_MAX, NULL);
	CommandArray.Add(NewCommand);

}

void InputManager::BindUI()
{
	//GBIND("inputMNG.typeMode", this, &InputManager::TypeMode)
	//GBIND("inputMNG.typeModePrime", this, &InputManager::PrimeTypeMode)
}

CommandC* InputManager::GetCommand(int InCommand)
{
	return CommandArray[InCommand];
}

void InputManager::BindCommandToKey(CommandC* CommandToBind, int32 KeyCode)
{
	if (CommandToBind->BoundKey() != -1)
	{
		InputMap.Remove(KeyCode);
	}

	CommandToBind->SetBoundKey(KeyCode);
}

void InputManager::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	int32 KeyCode = InKeyEvent.GetKeyCode();

	if (bPrimeTypeMode)
	{
			CharKey* PTK = PTKeyMap[KeyCode];
			if (PTK != nullptr)
			{
				//GSEND1("inputMNG.onPTKey", PTK->ID);
			}
	}
	else if(bRebindMode)
	{
		//Special Logic incase we are rebinding the key;
		return;
	} else {

		Glass_->Native()->OnKeyDown(MyGeometry, InKeyEvent);

		CommandC* Command;
		if (InputMap.Try(KeyCode, Command))
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sending");
			Command->Trigger(StrokeS(true));
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

		Glass_->Native()->OnKeyUp(MyGeometry, InKeyEvent);

		//Fires off Mod generated custom keys via a second TMap

		CommandC* Command;
		if (InputMap.Try(KeyCode, Command))
		{

			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sending");
			Command->Trigger(StrokeS(true));
		
		}

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(KeyCode));
	}

}

void InputManager::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
	if (bPrimeTypeMode)
	{
		//GSEND1("inputMNG.onChar", FString().AppendChar(InCharacterEvent.GetCharacter()));
	}
	else {
		Glass_->Native()->OnKeyChar(MyGeometry, InCharacterEvent);
	}
	
}
void InputManager::OnMouseMove(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{

	Glass_->Native()->OnMouseMove(MyGeometry,MouseEvent);
}

void InputManager::OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	Glass_->Native()->OnMouseButtonDown(MyGeometry, MouseEvent);
}

void InputManager::OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	Glass_->Native()->OnMouseButtonUp(MyGeometry, MouseEvent);
}

void InputManager::OnMouseWheel(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	Glass_->Native()->OnMouseWheel(MyGeometry,MouseEvent);
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
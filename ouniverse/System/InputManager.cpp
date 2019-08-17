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

#include "Min/DebugM.h"

#include <cohtml\Binding\String.h>



InputManager* InputManager::Create(DirS* InDirReg)
{
	return new InputManager(InDirReg);
}

InputManager::InputManager(DirS* InDirReg)
{	
	bRebindMode = false;
	bQuill = false;
	bCTR = false;
	bALT = false;

	//FileReadS* FileReader = new FileReadS(TCHAR_TO_ANSI(*(PathToReg + REG_INPUTMANAGER)));

	//JsonS* InputReg = new JsonS(FileReader->AsChar());
	//InputReg[];

	QuillKeyMap.Add(8, new CharKey(8, CharKey::Handler::Auto, CharKey::Modifier::None, "bs"));//BackSpace
	QuillKeyMap.Add(13, new CharKey(13, CharKey::Handler::Auto, CharKey::Modifier::None, "en"));//Enter
	QuillKeyMap.Add(38, new CharKey(38, CharKey::Handler::Auto, CharKey::Modifier::None, "du"));//DPadUp
	QuillKeyMap.Add(40, new CharKey(40, CharKey::Handler::Auto, CharKey::Modifier::None, "dd"));//DPadDown
	QuillKeyMap.Add(37, new CharKey(37, CharKey::Handler::Auto, CharKey::Modifier::None, "dl"));//DPadLeft
	QuillKeyMap.Add(39, new CharKey(39, CharKey::Handler::Auto, CharKey::Modifier::None, "dr"));//DPadRight
	QuillKeyMap.Add(67, new CharKey(67, CharKey::Handler::Switch, CharKey::Modifier::CTR, "copy"));//control c
	QuillKeyMap.Add(86, new CharKey(86, CharKey::Handler::Switch, CharKey::Modifier::CTR, "paste"));//control v
	QuillKeyMap.Add(65, new CharKey(65, CharKey::Handler::Switch, CharKey::Modifier::CTR, "seleall"));//control a

	CommandC* NewCommand = new CommandC();
	CommandArray.Init(Commands::COMMANDS_MAX, NULL);
	CommandArray.Add(NewCommand);

	GBIND("InputM.QuillStart", this, &InputManager::QuillStart)
	GBIND("InputM.QuillEnd", this, &InputManager::QuillEnd)
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

	if (KeyCode == 162)
	{
		bCTR = true;
	}

	if (KeyCode == 164)
	{
		bALT = true;
	}


	if (bQuill)
	{
		//DBUG(IFS(KeyCode))
		CharKey* CK;
		if (QuillKeyMap.Try(KeyCode, CK))
		{
				if (CK->IsValid(bCTR, bALT))
				{
					GSEND1("quill.onKeyDown", CK->ID_.ToChar());
				}
		}
	}
	else if(bRebindMode)
	{
		//Special Logic incase we are rebinding the key;
		return;
	} else {

		GlassC::Bridge()->OnKeyDown(MyGeometry, InKeyEvent);

		CommandC* Command;
		if (InputMap.Try(KeyCode, Command))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sending");
			Command->Trigger(StrokeS(true));
		}

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(KeyCode));
	}
}

void InputManager::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{

	int32 KeyCode = InKeyEvent.GetKeyCode();

	if (KeyCode == 162)
	{
			bCTR = false;
	}

	if (KeyCode == 164)
	{
		bALT = false;
	}

	if (!bQuill && !bRebindMode)
	{

		if (bRebindMode)
		{
			//Special Logic incase we are rebinding the key;
			return;
		}

		GlassC::Bridge()->OnKeyUp(MyGeometry, InKeyEvent);

		//Fires off Mod generated custom keys via a second TMap

		CommandC* Command;
		if (InputMap.Try(KeyCode, Command))
		{

			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sending");
			Command->Trigger(StrokeS(true));
		
		}

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(KeyCode));
	}

}

void InputManager::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
	if (bQuill)
	{
		StringC ThisChar = StringC(FString().AppendChar(InCharacterEvent.GetCharacter()));

		if (ThisChar.ContainsOnly(QuillChars))
		{
			//GSEND1("quill.onChar", FString().AppendChar(Result));
			GSEND1("quill.onChar", ThisChar.ToChar());
		}
		
	}
	else {
		GlassC::Bridge()->OnKeyChar(MyGeometry, InCharacterEvent);
	}
	
}
void InputManager::OnMouseMove(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	GlassC::Bridge()->OnMouseMove(MyGeometry,MouseEvent);
}

void InputManager::OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	GlassC::Bridge()->OnMouseButtonDown(MyGeometry, MouseEvent);
}

void InputManager::OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	GlassC::Bridge()->OnMouseButtonUp(MyGeometry, MouseEvent);
}

void InputManager::OnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	GlassC::Bridge()->OnMouseButtonDoubleClick(MyGeometry, MouseEvent);
}

void InputManager::OnMouseWheel(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	GlassC::Bridge()->OnMouseWheel(MyGeometry,MouseEvent);
}


void InputManager::QuillStart(std::string InChars)
{
		bQuill = true;
		QuillChars = StringC(InChars);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Quill Mode Enabled");

}

void InputManager::QuillEnd()
{
		bQuill = false;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Quill Mode Canceled");
	
}
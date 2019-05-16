//Copyright 2015-2019, All Rights Reserved.

/**
The InputManager is a Singleton extension to MAJOR and manages forwarding of all inputs.
Receives all inputs like keyboard and mouse interactions from a SlatePanel attached to the DisplayManager.

Has two maps:
InputMap pairs the DxScan int of a keypress with a CommandC object (system/command.h)
A command object holds a delegate which can be triggered and an ID.

CommandMap is where all the possible game commands get registered as CommandC Objects.

With this system keypresses can easily be registered to broadcast events.
Keybinds also are much easier because they only require changing the InputMap pair by moving the 
COMMAND object to be paired with the DxScan code of a different key.

There's some wonky pointers here that are pointing inputs from a Slate Widget SInput. 
Once InputManager receives the input it sends it to the UI Slate Widget (Coherent)
If Coherent doesn't consume the input then InputManager processes it.
 */


#pragma once

#include "CoreMinimal.h"
#include "Delegates/IDelegateInstance.h"

#include "UObject/NoExportTypes.h"
#include "cohtml/View.h"

#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/SlateCore/Public/Input/Events.h"


#include "Interface/Array.h"
#include "Interface/Map.h"

struct DirS;

class CommandC;
class CharKey;


class SCohtmlInputForward;
class GlassC;

class OUNIVERSE_API InputManager
{


private:

	InputManager(DirS* InDirReg, GlassC* InGlass);

public:

	static InputManager* Create(DirS* InDirReg, GlassC* InGlass);

	void TypeMode(int bEnabled);
	void PrimeTypeMode(int bEnabled);
	

	void OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);
	void OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);
	void OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent);

	void OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

	CommandC* GetCommand(int InCommand);


private:

	enum class CommandType : uint8
	{
		Global,
		Multi,
		Character,
	};


	//Major->UiManager->Ui->GetView()
	//UCohtmlBaseComponent* UiView
	GlassC* Glass_;



	bool bRebindMode;
	bool bTypeMode;
	bool bPrimeTypeMode;


	ArrayC<CommandC*> CommandArray;

	enum Commands
	{
		Console,
		COMMANDS_MAX,
	};

	MapC<int32,CommandC*> InputMap;
	MapC<int32, CharKey*> PTKeyMap;

	void BindUI();

	void BindCommandToKey(CommandC* CommandToBind, int32 KeyCode);

};
//Copyright 2015-2019, All Rights Reserved.

/**

## InputManager

> **Singleton Service: Created once only by the boot process.**

A service singleton the manages all input events.
Receives all inputs like keyboard and mouse interactions from the SInputCatch widget.

#### CommandArray
- Creates all the input Commands used by the game by setting up a class with Event Delegates inside.
- Command's event delegates can be registered for.
- Creates a ENUM based map for easy access by the C++ code and also a keycode map to convert key presses to commands
- The keycode map allows for easy rebinding as well.

#### CharKeyArray
- Same as CommandArray but handles Char Key presses while in typing mode.

**Creator:** UBoot
**Holder:** Major

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
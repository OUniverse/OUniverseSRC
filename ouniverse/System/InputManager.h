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
#include "Interface/String.h"
#include "Interface/Url.h"
#include "System/KeyCode.h"

#include "System/Command.h"

class BootC;

class CommandC;
class CommandLayerC;

class CharKey;

class SCohtmlInputForward;
class GlassC;



class OUNIVERSE_API InputManager
{

	friend BootC;

private:

	 InputManager(NewFileC InRegFile);

public:

	void QuillStart(std::string InChars);
	void QuillEnd();

	void OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);
	void OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);
	void OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent);

	void OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);


	enum Layer
	{
		Menu,
		World,
		LAYER_MAX,
	};

	CommandE ListenToCMD(Layer InLayer, int InCMD);

private:


	bool bCTR;
	bool bALT;

	bool bRebindMode;
	bool bQuill;

	StringC QuillChars;


	MapC<int, CharKey*> QuillKeyMap;

	CommandLayerC* ActiveLayer_;

	void ActivateLayer(Layer ActiveLayer);

	CommandLayerC* AddLayer(Layer InLayerType, CommandLayerC* InCommand);
	ArrayC<CommandLayerC*> Layers_;
};


class CommandLayerC
{

public:

	CommandLayerC(int InCMD_MAX);


	CommandE Listen(int InCMD);

	bool Try(KeyCodeC InKeyCode, CommandC*& InCommand);

	void Add(int InCMD, KeyCodeC KeyCode);

	void Rebind(int InCMD, KeyCodeC KeyCode);

public:


	ArrayC<CommandC*> Commands_;
	MapC<KeyCodeC, CommandC*> Input_;


};


class CommandLayerMenuC : public CommandLayerC
{
	
public:

	enum CMD
	{
		Console,
		Escape,
		Enter,
		Space,
		MAX,
	};

};


class CommandLayerWorldC : public CommandLayerC
{

public:

	enum CMD
	{
		Interact,
		Jump,
		Run,
		Stealth,
		MainMenu,
	};

};
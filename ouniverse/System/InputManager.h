//Copyright 2015-2019, All Rights Reserved.

/**
The InputManager is a Singleton extension to MAJOR and manages forwarding of all inputs.
Receives all inputs like keyboard and mouse interactions from a SlatePanel attached to the DisplayManager.

Has two maps:
InputMap pairs the DxScan int of a keypress with a Command object (system/command.h)
A command object holds a delegate which can be triggered and an ID.

CommandMap is where all the possible game commands get registered as Command Objects.

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
#include <map>

#include "UObject/NoExportTypes.h"
#include "cohtml/View.h"

#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/SlateCore/Public/Input/Events.h"

#include "InputManager.generated.h"


class UCommand;
class UPTKey;

class UCohtmlBaseComponent;
class UInputManager;
class UCohtmlHUD;
class SCohtmlInputForward;

class OUNIVERSE_API InputManager
{


private:

	InputManager(UCohtmlHUD* InUi,TSharedPtr<class SCohtmlInputForward> InNativeUi,FString PathToReg);

public:

	static InputManager* Create(UCohtmlHUD* InUi, TSharedPtr<class SCohtmlInputForward> InNativeUi, FString PathToReg);
	
	UInputManagerProxy* Proxy;
	void TypeMode(int bEnabled);
	void PrimeTypeMode(int bEnabled);
	

	void OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);
	void OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);
	void OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent);

	void OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	void OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

	UCommand* GetCommand(FString CommandName);


private:

	enum class CommandType : uint8
	{
		Global,
		Multi,
		Character,
	};


	//Major->UiManager->Ui->GetView()
	//UCohtmlBaseComponent* UiView
	UCohtmlHUD* Ui;
	TSharedPtr<class SCohtmlInputForward> UiNative;



	bool bRebindMode;
	bool bTypeMode;
	bool bPrimeTypeMode;


	std::map <FName,UCommand*> CommandMap;
	std::map <int32,UCommand*> InputMap;
	std::map <int32, UPTKey*> PTKeyMap;

	void BindUI();

	void BindCommandToKey(UCommand* CommandToBind, int32 KeyCode);

};





UCLASS()
class OUNIVERSE_API UInputManagerProxy : public UObject
{
	GENERATED_BODY()

public:

	void Init(InputManager* Input);

	InputManager* Relay;

	void TypeMode(int bEnabled);
	void PrimeTypeMode(int bEnabled);
};

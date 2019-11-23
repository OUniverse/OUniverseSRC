//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Interface.h"
#include "Ui_Interactive.generated.h"



UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EUi_InteractiveEvent : uint8
{
	Click 		UMETA(DisplayName = "Click"),
	MouseDown 	UMETA(DisplayName = "MouseDown"),
	MouseUp 	UMETA(DisplayName = "MouseUp"),
	MouseEnter 	UMETA(DisplayName = "MouseEnter"),
	MouseExit	UMETA(DisplayName = "MouseExit"),
	MouseMove	UMETA(DisplayName = "MouseMove"),
};

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API UUi_Interactive : public UUi_Interface
{

	GENERATED_BODY()

public:

	
	bool LockState;

	void SetLock(bool InLockState);
	void SetHide(bool InHide);

	void Select();
	
	void SetFocus(bool InFocus) {};

	UFUNCTION(BlueprintCallable)
	int InteractiveEvent(EUi_InteractiveEvent InteractionType);

	UFUNCTION(BlueprintCallable)
	int DoClick();

	UFUNCTION(BlueprintCallable)
	int DoTextChanged();

	UFUNCTION(BlueprintCallable)
	int DoTextCommit(int CommitMethod);



	int Click_Mechanism();
	int PreciseClick_Mechanism();
	int MouseDown_Mechanism();
	int MouseUp_Mechanism();
	int MouseEnter_Mechanism();
	int MouseExit_Mechanism();
	int MouseMove_Mechanism();
	int TextChanged_Mechanism();
	int TextCommit_Mechanism(int CommitMethod);

};
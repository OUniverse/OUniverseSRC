//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_Base.h"
#include "System/Input.h"

#include "Ui_El.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_El : public UUi_Base
{

	GENERATED_BODY()

public:


	virtual void InitNEW();

	void Cancel();


	
	void ControlFocus_Mechanism(UUi_El* ControlParent) {};
	void ControlUnfocus_Mechanism() {};

	void ControlFocus() {};
	void ControlUnfocus() {};

	void ControlRelay(UUi_El* Relay);
	void ControlClaim();

	bool ACT_Up(FUiAction Action) { return false; };
	bool ACT_Down(FUiAction Action) { return false; };
	bool ACT_Left(FUiAction Action) { return false; };
	bool ACT_Right(FUiAction Action) { return false; };

	bool ACT_Accept(FUiAction Action) { return false; };
	bool ACT_Cancel(FUiAction Action) { return false; };

private:


	UUi_El* ControlParent_;
	UUi_El* ControlChild_;

};
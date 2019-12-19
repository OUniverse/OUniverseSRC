//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiBase.h"
#include "System/InputData.h"

#include "UiEl.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUiEl : public UUiBase
{

	GENERATED_BODY()

public:

	int GetElementID();

	void SetElementID(int InElementID);

	void ConstructEl();

	void ControlFocus_Mechanism(UUiEl* ControlParent) {};
	void ControlUnfocus_Mechanism() {};

	void ControlFocus() {};
	void ControlUnfocus() {};

	void ControlRelay(UUiEl* Relay);
	void ControlClaim();
	 
	bool InputCommand_Mechanism(KeyS InKey);
	bool InputAxis_Mechanism(AxisS InAxis);

	virtual bool InputCommand(KeyS InKey);
	virtual bool InputAxis(AxisS InAxis);



private:
	
	int ElementID_;

	UUiEl* ControlParent_;
	UUiEl* ControlChild_;

};
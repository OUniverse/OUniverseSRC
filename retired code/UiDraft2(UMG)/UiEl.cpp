//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiEl.h"



void UUiEl::ConstructEl()
{
	ControlChild_ = NULL;
	ElementID_ = -1;
}


int UUiEl::GetElementID()
{
	return ElementID_;
}

void UUiEl::SetElementID(int InElementID)
{
	ElementID_ = InElementID;
}

void UUiEl::ControlRelay(UUiEl* Relay)
{
	ControlChild_ = NULL;
	ControlChild_ = Relay;
}

void UUiEl::ControlClaim()
{
	ControlChild_ = this;
}

bool UUiEl::InputCommand_Mechanism(KeyS InKey)
{
	if (ControlChild_ != NULL)
	{
		return ControlChild_->InputCommand_Mechanism(InKey);
	}
	return InputCommand(InKey);
};

bool UUiEl::InputCommand(KeyS InKey)
{
	return false;
};

bool UUiEl::InputAxis_Mechanism(AxisS InAxis)
{
	if (ControlChild_ != NULL)
	{
		ControlChild_->InputAxis_Mechanism(InAxis);
	}
	return InputAxis(InAxis);
};

bool UUiEl::InputAxis(AxisS InAxis)
{
	return false;
};
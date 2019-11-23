//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Interactive.h"
#include "Ui/Ui_Pylon.h"
#include "Types/SlateEnums.h"

int UUi_Interactive::InteractiveEvent(EUi_InteractiveEvent InteractionType)
{
	switch (InteractionType) {
	case EUi_InteractiveEvent::Click:
		return Click_Mechanism();
	case EUi_InteractiveEvent::MouseDown:
		return MouseDown_Mechanism();
	case EUi_InteractiveEvent::MouseUp:
		return MouseUp_Mechanism();
	case EUi_InteractiveEvent::MouseEnter:
		return MouseEnter_Mechanism();
	case EUi_InteractiveEvent::MouseExit:
		return MouseExit_Mechanism();
	case EUi_InteractiveEvent::MouseMove:
		return MouseMove_Mechanism();
	}

	return 0;
}


int UUi_Interactive::DoClick()
{
	return Click_Mechanism();
}

int UUi_Interactive::DoTextChanged()
{
	return TextChanged_Mechanism();
}

int UUi_Interactive::DoTextCommit(int CommitMethod)
{
	return TextCommit_Mechanism(CommitMethod);
}

int UUi_Interactive::Click_Mechanism()
{
	Relay_->Click(this);
	return 0;
}

int UUi_Interactive::PreciseClick_Mechanism()
{
	Relay_->PreciseClick(this);
	return 0;
}


int UUi_Interactive::MouseDown_Mechanism()
{
	Relay_->MouseDown(this);
	return 0;
}

int UUi_Interactive::MouseUp_Mechanism()
{
	Relay_->MouseUp(this);
	return 0;
}

int UUi_Interactive::MouseEnter_Mechanism()
{
	Relay_->MouseEnter(this);
	return 0;
}

int UUi_Interactive::MouseExit_Mechanism()
{
	Relay_->MouseExit(this);
	return 0;
}

int UUi_Interactive::MouseMove_Mechanism()
{
	Relay_->MouseMove(this);
	return 0;
}


int UUi_Interactive::TextChanged_Mechanism()
{
	Relay_->MouseExit(this);
	return 0;
}

int UUi_Interactive::TextCommit_Mechanism(int CommitMethod)
{
	Relay_->TextCommit(this, CommitMethod);
	return 0;
}
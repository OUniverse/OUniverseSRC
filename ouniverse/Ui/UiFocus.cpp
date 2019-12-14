//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiFocus.h"

void UUiFocus::SetupFocus(FocusUiC* InFocus)
{
	Focus_ = InFocus;
}

void UUiFocus::Focus_Mechanism()
{
	FocusBP();
}

void UUiFocus::Unfocus_Mechanism()
{
	UnfocusBP();
}
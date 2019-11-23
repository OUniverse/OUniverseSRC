//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Bool.h"
#include "Ui/Ui_Interface.h"

bool UUi_Bool::GetValue()
{
	return Value;
}

void UUi_Bool::Toggle()
{
	Value = !Value;
	Update();
	Changed();
}

void UUi_Bool::Set(bool SetTo, bool bInternalOnly)
{
	Value = SetTo;
	Update();

	if (!bInternalOnly)
	{
		Changed();
	}
}
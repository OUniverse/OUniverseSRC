//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Bool.h"

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

void UUi_Bool::Set(bool SetTo)
{
	Value = SetTo;
	Update();
	Changed();
}

void UUi_Bool::SetNoChanged(bool SetTo)
{
	Value = SetTo;
	Update();
}
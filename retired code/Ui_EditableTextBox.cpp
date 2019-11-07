//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_EditableTextBox.h"

void UUi_EditableTextBox::SetRelay(UUbc* InRelay)
{
	Relay_ = InRelay;
}

UUbc* UUi_EditableTextBox::Relay()
{
	return Relay_;
}
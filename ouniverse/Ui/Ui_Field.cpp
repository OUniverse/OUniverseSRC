//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Field.h"



void UUi_Field::Ready()
{
	OnReady();
}

int UUi_Field::GetFieldBID()
{
	return BID_;
}

int UUi_Field::GetFieldFID()
{
	return FID_;
}

int UUi_Field::GetFieldHelpUID()
{
	return HelpUID_;
}
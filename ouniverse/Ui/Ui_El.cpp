//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_El.h"





void UUi_El::InitNEW()
{
	ControlChild_ = NULL;
}

void UUi_El::ControlRelay(UUi_El* Relay)
{
	ControlChild_ = Relay;
}

void UUi_El::ControlClaim()
{
	ControlChild_ = NULL;
}
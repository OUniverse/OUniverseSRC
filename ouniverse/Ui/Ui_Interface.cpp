//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Interface.h"



void UUi_Interface::SetupInterface(UUi_Pylon* InRelay, int InInterfaceUID)
{
	Relay_ = InRelay;
	InterfaceUID_ = InInterfaceUID;
	InterfaceSetup();
}

UUi_Pylon* UUi_Interface::Relay()
{
	return Relay_;
}


int UUi_Interface::InterfaceUID()
{
	return InterfaceUID_;
}
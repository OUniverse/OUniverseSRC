//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Relay.h"



void UUi_Relay::SetRelay(UUbc* InRelay)
{
	Relay_ = InRelay;
	RelaySet();
}

UUbc* UUi_Relay::Relay()
{
	return Relay_;
}

void UUi_Relay::SetRelayUID(int InRelayUID)
{
	RelayUID_ = InRelayUID;
}


int UUi_Relay::RelayUID()
{
	return RelayUID_;
}
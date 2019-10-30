//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/GlobalPro.h"

#include "Min/DebugM.h"

UGlobalPro::UGlobalPro() : UProtocol()
{

}

UGlobalPro* UGlobalPro::Create()
{
	return NewObject<UGlobalPro>();
}

bool UGlobalPro::Up(bool Down)
{
	return false;
}
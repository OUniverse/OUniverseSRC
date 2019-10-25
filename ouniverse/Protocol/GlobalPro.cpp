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

InputReplyS UGlobalPro::Forward(InputActionS InIA)
{
	DBUG("WE HAVE ACHIEVED THE GOAL");
	return InputReplyS();
}
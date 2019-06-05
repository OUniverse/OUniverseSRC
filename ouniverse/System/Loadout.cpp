//Copyright 2015-2019, All Rights Reserved.

#include "System/Loadout.h"

#include "Interface/Json.h"


LoadoutC::LoadoutC(StringC InStr)
{
	JsonS J = JsonS(StringC(InStr));
	UID_ = J.ToUInt8("ID");

}

UInt8 LoadoutC::GetUID()
{
	return UID_;
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/Data.h"

#include "System/Payload.h"

#include "System/Log.h"
#include "System/Loadout.h"

namespace GlobalSingleton
{
	DataC Data;
}

DataC* DataC::Get()
{
	return &GlobalSingleton::Data;
}

DataC* DataC::Create(StringC InPath)
{
	GlobalSingleton::Data = *(new DataC(InPath));
	return &GlobalSingleton::Data;
}

DataC::DataC(StringC InPath)
{
	Path_ = InPath;
	Payload_ = new PayloadC(Path_);
}

DataC::DataC()
{

}

void DataC::ResetPayload(LoadoutC* InLoadout)
{
	Payload_->Reset(InLoadout);
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/Data.h"
#include "System/AtlasLib.h"
#include "System/Atlas.h"

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
	AtlasLib_ = new AtlasLibC(Path_);
}

ArrayC<AtlasC*> DataC::GetAtlasPreArray()
{
	return AtlasLib_->GetAtlasPreArray();
}

DataC::DataC()
{

}

AtlasLibC* DataC::GetAtlasLib()
{
	return AtlasLib_;
}

ArrayC<FormPilotS> DataC::GetFormPilots()
{
	return AtlasLib_->GetFormPilots();
}

FormQueryS DataC::Query(FormQueryS InQuery)
{
	return AtlasLib_->Query(InQuery);
}

/**
void DataC::Reset(LoadoutC* InLoadout)
{
	Payload_->Reset(InLoadout);
}

void DataC::Evolve(CosmosC* InLoadout)
{
	Payload_->Evolve(InLoadout);
}
*/
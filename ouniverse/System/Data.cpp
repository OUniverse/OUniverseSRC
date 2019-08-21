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


void DataC::Query(FormQueryS* InQuery)
{
	AtlasLib_->Query(InQuery);
}

FormWrapS DataC::GetFormWrap(U64 InAtlas, U32 InForm)
{
	return AtlasLib_->Get(InAtlas)->GetFormWrap(InForm);
}

void DataC::UpdateForm(U64 InAtlasUID, U32 InUID, JsonS& FormJ)
{
	AtlasLib_->Get(InAtlasUID)->UpdateForm(InUID, FormJ);
}

void DataC::UpdateAtlas(U64 InAtlasUID, JsonS& AtlasJ)
{
	AtlasLib_->Get(InAtlasUID)->Update(AtlasJ);
}

void DataC::SaveAtlasDoc(U64 InAtlasUID)
{
	AtlasLib_->Get(InAtlasUID)->SaveDoc();
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
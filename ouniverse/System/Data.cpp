//Copyright 2015-2019, All Rights Reserved.

#include "System/Data.h"
#include "System/AtlasLib.h"
#include "System/Atlas.h"
#include "System/Loadout.h"

namespace GlobalSingleton
{
	DataC Data;
}

DataC* DataC::Get()
{
	return &GlobalSingleton::Data;
}

DataC* DataC::Create(FolderC InPath)
{
	GlobalSingleton::Data = *(new DataC(InPath));
	return &GlobalSingleton::Data;
}

DataC::DataC(FolderC InAtlasFolder)
{
	AtlasFolder_ = InAtlasFolder;
	AtlasLib_ = new AtlasLibC(AtlasFolder_);
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

void DataC::Mount(LoadoutC* InLoadout)
{
	AtlasLib_->Mount(InLoadout->GetSelectedAtlasi());
}

void DataC::Query(FormQueryS* InQuery)
{
	AtlasLib_->Query(InQuery);
}

FormWrapS DataC::GetFormWrap(DuetUID InDuet)
{
	return AtlasLib_->Get(InDuet.Atlas())->GetFormWrap(InDuet.Form());
}

void DataC::UpdateForm(DuetUID InDuet, JsonS& FormJ)
{
	AtlasLib_->Get(InDuet.Atlas())->UpdateForm(InDuet.Form(), FormJ);
}

void DataC::UpdateAtlas(AtlasUID InAtlasUID, JsonS& AtlasJ)
{
	AtlasLib_->Get(InAtlasUID)->Update(AtlasJ);
}

void DataC::SaveAtlasDoc(AtlasUID InAtlasUID)
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
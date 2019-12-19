//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ex/WriData.h"

#include "System/Atlas.h"
#include "System/AtlasLib.h"

AtlasDataStorageS::AtlasDataStorageS(AtlasC* InAtlas)
{
	ID = InAtlas->ID();
	Name = InAtlas->Name();
	Author = InAtlas->Author();
	Website = InAtlas->Website();
	Socket = InAtlas->WebSocket();
}




WriDataC::WriDataC(AtlasLibC* InAtlasLib)
{
	MasterAtlas_ = NULL;
	LoadoutLocked_ = false;
	AtlasLib_ = InAtlasLib;
}

void WriDataC::SetMaster(AtlasC* InMaster)
{
	if (MasterAtlas_ != NULL)
	{
		UnloadMaster();
	}

	MasterAtlas_ = InMaster;
}

void WriDataC::Mount()
{
	LoadMaster();
	AtlasLib_->MountFromWriter(&Loadout_);
}

void WriDataC::Dismount()
{

}


void WriDataC::LoadMaster()
{
	AtlasStorage_ = AtlasDataStorageS(MasterAtlas_);
}

void WriDataC::UnloadMaster()
{
	MasterAtlas_->ID_ = AtlasStorage_.ID;
	MasterAtlas_->Name_ = AtlasStorage_.Name;
	MasterAtlas_->Author_ = AtlasStorage_.Author;
	MasterAtlas_->Website_ = AtlasStorage_.Website;
	MasterAtlas_->WebSocket_ = AtlasStorage_.Socket;
}
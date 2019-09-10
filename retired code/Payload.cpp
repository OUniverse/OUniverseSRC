//Copyright 2015-2019, All Rights Reserved.

#include "System/Payload.h"

#include "System/Log.h"

#include "System/Loadout.h"
#include "System/AtlasLib.h"


PayloadC::PayloadC(StringC InPath)
{
	LOG(30000, "PayloadC", "Initializing $V$.")
	Path_ = InPath;

	AtlasLib_ = new AtlasLibC(Path_);
}


void PayloadC::Reset(LoadoutC* InLoadout)
{
	LOG(25906, Void(), "Resetting the payload.")
	//AtlasLib_->Reset();
	//AtlasLib_->Promote(InLoadout);
}

void PayloadC::Evolve(CosmosC* InCosmos)
{
	//AtlasLib_->Evolve(InCosmos);
}
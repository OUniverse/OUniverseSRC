//Copyright 2015-2019, All Rights Reserved.

#include "System/Payload.h"
#include "System/Atlas.h"

#include "Interface/DirQuery.h"

#include "Data/World.h"

#include "System/Log.h"

#include "Form/FactoryF.h"

#include "System/Loadout.h"

PayloadC::PayloadC(StringC InPath)
{
	LOG(30000, "PayloadC", "Initializing $V$.")

	Path_ = InPath;

	Factory = new FactoryF();

	DirQueryS Fo = DirQueryS(Path_);
	LOG(31258,  Path_/""," Scanning directory : $V$")
	
	for (int i = 0; i < Fo.Num(); i++)
	{
		AtlasC* NewAtlas = new AtlasC(Fo.Folder(i),Fo.Full(i));

		if (NewAtlas->Valid())
		{
			AtlasMap.Add(NewAtlas->UID(), NewAtlas);
		}
		else 
		{
			delete NewAtlas;
		}		
	}
}

void PayloadC::Reset(LoadoutC* InLoadout)
{
	LOG(25906, Void(), "Resetting the payload.")
	int M = AtlasMap.Len();

	AtlasC* TryAtlas;

	for (int m = 0; m < M; m++)
	{
		TryAtlas = AtlasMap.At(m);
		if (TryAtlas->Promoted())
		{
			LOG(12838, TryAtlas->UID(), "Demoting Atlas: $V$")
			TryAtlas->Demote();
		}
	}

	int L = InLoadout->Atlases_.Len();

	for (int i = 0; i < L; i++)
	{	
		if (AtlasMap.Try(InLoadout->Atlases_[i].UID_, TryAtlas))
		{
			LOG(11922, TryAtlas->UID(), "Promoting Atlas: $V$")
			TryAtlas->Promote();
		}
	}
}
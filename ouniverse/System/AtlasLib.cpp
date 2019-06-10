//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasLib.h"
#include "System/Atlas.h"
#include "System/Loadout.h"
#include "System/CreditLib.h"
#include "System/Cosmos.h"

#include "Interface/DirQuery.h"

#include "System/Log.h"

AtlasLibC::AtlasLibC(StringC InPath)
{
	PreLen_ = 0;
	Len_ = 0;
	Path_ = InPath;
	CreditLib_ = new CreditLibC();

	DirQueryS Fo = DirQueryS(Path_);
	LOG(31258, Path_ / "", " Scanning directory : $V$")

		for (int i = 0; i < Fo.Num(); i++)
		{
			AtlasC* New = new AtlasC(Fo.Folder(i), Fo.Full(i));

			if (New->Valid())
			{
				AddPreAtlas(New);
			}
			else
			{
				delete New;
			}
		}

	for (int i = 0; i < PreLen_; i++)
	{
		PreLib_.At(i)->CheckRequirements(this);
	}

	for (int i = 0; i < PreLen_; i++)
	{
		AtlasC* Seek = NULL;
		Seek = PreLib_.At(i);
		Seek->Survey(this);
		CreditLib_->GetCreditsFromAtlas(Seek->Path());
	}

}


void AtlasLibC::AddPreAtlas(AtlasC* NewAtlas)
{
	PreLen_++;
	PreLib_.Add(NewAtlas->UID(), NewAtlas);
}

void AtlasLibC::AddAtlas(AtlasC* NewAtlas)
{
	Len_++;
	Lib_.Add(NewAtlas->UID(), NewAtlas);
}

AtlasC* AtlasLibC::operator[](U64 InValue)
{
	return PreLib_[InValue];
}

AtlasC* AtlasLibC::At(int Index)
{
	return PreLib_.At(Index);
}

int AtlasLibC::PreLen()
{
	return PreLen_;
}

int AtlasLibC::Len()
{
	return Len_;
}

bool AtlasLibC::Try(U64 InUID, AtlasC* Out)
{
	return PreLib_.Try(InUID, Out);
}

void AtlasLibC::Reset()
{
	for (int m = 0; m < PreLen_; m++)
	{
		//LOG(12838, TryAtlas->UID(), "Demoting Atlas: $V$")
		PreLib_.At(m)->Demote();
	}
}

void AtlasLibC::Evolve(CosmosC* InCosmos)
{
	for (int m = 0; m < PreLen_; m++)
	{
		//LOG(12838, TryAtlas->UID(), "Demoting Atlas: $V$")
		PreLib_.At(m)->Evolve(InCosmos);
	}
}

void AtlasLibC::Promote(LoadoutC* InLoadout)
{
	//Promote all new atlases from the selected loadout.

	int L = InLoadout->Atlases_.Len();
	AtlasC* TryAtlas;

	for (int i = 0; i < L; i++)
	{
		if (PreLib_.Try(InLoadout->Atlases_[i].UID_, TryAtlas))
		{
			LOG(11922, TryAtlas->UID(), "Promoting Atlas: $V$")
			AddAtlas(TryAtlas);
			TryAtlas->Promote();
		}
	}

	for (int i = 0; i < Len_; i++)
	{
		LOG(34817, Void(), "Linking FORMS in the BOOST phase.")
		Lib_.At(i)->LinkBoost(this);
	}
}
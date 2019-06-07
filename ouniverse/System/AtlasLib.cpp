//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasLib.h"
#include "System/Atlas.h"
#include "System/Loadout.h"

#include "Interface/DirQuery.h"

#include "System/Log.h"

AtlasLibC::AtlasLibC(StringC InPath)
{
	Len_ = 0;
	Path_ = InPath;

	DirQueryS Fo = DirQueryS(Path_);
	LOG(31258, Path_ / "", " Scanning directory : $V$")

		for (int i = 0; i < Fo.Num(); i++)
		{
			AtlasC* New = new AtlasC(Fo.Folder(i), Fo.Full(i));

			if (New->Valid())
			{
				Lib_.Add(New->UID(), New);
			}
			else
			{
				delete New;
			}
		}

	for (int i = 0; i < Len_; i++)
	{
		Lib_.At(i)->CheckRequirements(this);
	}

	for (int i = 0; i < Len_; i++)
	{
		Lib_.At(i)->Survey(this);
	}
}


AtlasC* AtlasLibC::operator[](U64 InValue)
{
	return Lib_[InValue];
}

AtlasC* AtlasLibC::At(int Index)
{
	return Lib_.At(Index);
}

void AtlasLibC::Add(U64 InUID, AtlasC* InAtlas)
{
	Len_++;
	Lib_.Add(InUID, InAtlas);
}

int AtlasLibC::Len()
{
	return Len_;
}

bool AtlasLibC::Try(U64 InUID, AtlasC* Out)
{
	return Lib_.Try(InUID, Out);
}

void AtlasLibC::Reset()
{
	for (int m = 0; m < Len_; m++)
	{
		//LOG(12838, TryAtlas->UID(), "Demoting Atlas: $V$")
		Lib_.At(m)->Demote();
	}
}

void AtlasLibC::Promote(LoadoutC* InLoadout)
{
	//Promote all new atlases from the selected loadout.

	int L = InLoadout->Atlases_.Len();
	AtlasC* TryAtlas;

	for (int i = 0; i < L; i++)
	{
		if (Lib_.Try(InLoadout->Atlases_[i].UID_, TryAtlas))
		{
			LOG(11922, TryAtlas->UID(), "Promoting Atlas: $V$")
			TryAtlas->Promote();
		}
	}
}
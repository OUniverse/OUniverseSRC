//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasLib.h"
#include "System/Atlas.h"
#include "System/Loadout.h"

#include "System/Log.h"

#include "Min/DebugM.h"


AtlasLibC::AtlasLibC(FolderC InAtlasFolder)
{
	PreLen_ = 0;
	Len_ = 0;
	AtlasFolder_ = InAtlasFolder;

	ArrayC<FolderC> Fo = AtlasFolder_.GetFolders();
	LOG(31258, AtlasFolder_.ToString() / "", " Scanning directory : $V$")

		int l = Fo.Len();
		for (int i = 0; i < l; i++)
		{
			AtlasC* New = new AtlasC(Fo[i].GetFinalDir(), Fo[i]);

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
		//CreditLib_->GetCreditsFromAtlas(Seek->Path());
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

ArrayC<AtlasC*> AtlasLibC::GetAtlasPreArray()
{
	int l = PreLib_.Len();
	ArrayC<AtlasC*> AtlasPreArr;

	for (int i = 0; i < l; i++)
	{
		AtlasPreArr.Add(PreLib_.At(i));
	}

	return AtlasPreArr;
}

AtlasC* AtlasLibC::Get(AtlasUID InValue)
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

bool AtlasLibC::Try(AtlasUID InUID, AtlasC* Out)
{
	return PreLib_.Try(InUID, Out);
}

void AtlasLibC::Reset()
{
	for (int m = 0; m < PreLen_; m++)
	{
		//LOG(12838, TryAtlas->UID(), "Demoting Atlas: $V$")
		PreLib_.At(m)->Dismount();
	}
}

void AtlasLibC::Mount(ArrayC<AtlasUID> InUIDArr)
{
	int L = InUIDArr.Len();
	AtlasC* TryAtlas;

	for (int i = 0; i < L; i++)
	{
		if (PreLib_.Try(InUIDArr[i], TryAtlas))
		{
			LOG(11922, TryAtlas->UID().ForLog(), "Promoting Atlas: $V$")
			AddAtlas(TryAtlas);
			TryAtlas->Mount(this);
		}
	}
}

void AtlasLibC::Query(FormQueryS* InQuery)
{

	for (int i = 0; i < Len(); i++)
	{
		Lib_.At(i)->Query(InQuery);
	}

}
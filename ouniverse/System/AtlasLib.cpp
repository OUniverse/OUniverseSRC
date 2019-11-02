//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasLib.h"
#include "System/Atlas.h"
#include "System/Atlas_.h"
#include "System/Loadout.h"

#include "System/Log.h"

#include "Min/DebugM.h"


namespace Global
{
	AtlasLibC* AtlasLib;
}

AtlasLibC* AtlasLibC::Get()
{
	return Global::AtlasLib;
}

AtlasLibC* AtlasLibC::Create(FolderC InFolder)
{
	AtlasLibC* Neu = new AtlasLibC(InFolder);
	Global::AtlasLib = Neu;
	return Neu;
}

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

AtlasC* AtlasLibC::GetAtlas(AtlasUID InValue)
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

bool AtlasLibC::Try(AtlasUID InUID, AtlasC*& Out)
{
	return PreLib_.Try(InUID, Out);
}

bool AtlasLibC::TryForm(DuetUID DUID, FormF*& InForm, int& Error)
{
	AtlasC* tAtlas;
	Error = 0;

	bool bFound = Try(DUID.Atlas(),tAtlas);
	
	if (bFound)
	{
		
		bFound = tAtlas->Try(DUID.Form(), InForm);
		if (!bFound)
		{
			Error = 2;
		}
	}
	else
	{
		Error = 1;
	}

	return bFound;
}

void AtlasLibC::Reset()
{
	for (int m = 0; m < PreLen_; m++)
	{
		//LOG(12838, TryAtlas->UID(), "Demoting Atlas: $V$")
		PreLib_.At(m)->Dismount();
	}
}

void AtlasLibC::Mount(LoadoutC* InLoadout)
{
	ArrayC<AtlasUID> UIDArr = InLoadout->GetSelectedAtlasi();
	int L = UIDArr.Len();
	AtlasC* TryAtlas;

	for (int i = 0; i < L; i++)
	{
		if (PreLib_.Try(UIDArr[i], TryAtlas))
		{
			LOG(11922, TryAtlas->UID().ForLog(), "Promoting Atlas: $V$")
			AddAtlas(TryAtlas);
			TryAtlas->Mount(this);
		}
	}

	L = Lib_.Len();

	for (int i = 0; i < L; i++)
	{
		Lib_.At(i)->Demarshal();
	}
}

void AtlasLibC::Query(FormQueryS* InQuery)
{

	for (int i = 0; i < Len(); i++)
	{
		Lib_.At(i)->Query(InQuery);
	}

}

FormWrapS AtlasLibC::GetFormWrap(DuetUID InDuet)
{
	return GetAtlas(InDuet.Atlas())->GetFormWrap(InDuet.Form());
}

void AtlasLibC::UpdateForm(DuetUID InDuet, JsonS& FormJ)
{
	GetAtlas(InDuet.Atlas())->UpdateForm(InDuet.Form(), FormJ);
}

void AtlasLibC::UpdateAtlas(AtlasUID InAtlasUID, JsonS& AtlasJ)
{
	GetAtlas(InAtlasUID)->Update(AtlasJ);
}

void AtlasLibC::SaveAtlasDoc(AtlasUID InAtlasUID)
{
	GetAtlas(InAtlasUID)->SaveDoc();
}


TArray<UAtlas*> AtlasLibC::Consulify()
{
	TArray<UAtlas*> Consul;

	for (int i = 0; i < PreLen_; i++)
	{
		UAtlas* Atl = UAtlas::Create(PreLib_.At(i));
		Consul.Emplace(Atl);
	}

	return Consul;
}
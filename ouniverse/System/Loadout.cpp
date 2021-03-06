//Copyright 2015-2019, All Rights Reserved.

#include "System/Loadout.h"
#include "Key/GlobalK.h"
#include "Key/LoadoutK.h"
#include "Interface/Json.h"

#include "System/Log.h"


LoadoutC* LoadoutC::Create()
{
	LoadoutC* Neu = new LoadoutC();
	return Neu;
}

LoadoutC::LoadoutC()
{
	Valid_ = false;
	NoSave_ = false;
}

void LoadoutC::JsonMethod(JsonS* InJ)
{
	LOG(14561, Void(), "Processing New Loadout...")

	if (!InJ->Has(GlobalK::UID))
	{
		LOG(300, GlobalK::UID, "Missing required Json Value: $V$")
			return;
	}

	if (!InJ->Has(GlobalK::ID))
	{
		LOG(300, GlobalK::ID, "Missing required Json Value: $V$")
			return;
	}

	if (!InJ->Has(GlobalK::Glyph))
	{
		LOG(300, GlobalK::Glyph, "Missing required Json Value: $V$")
			return;
	}

	if (!InJ->Key(GlobalK::UID).IsNumber())
	{
		LOG(301, GlobalK::UID, "Expected a Json Number but value was wrong type: $V$﻿")
			return;
	}

	if (!InJ->Key(GlobalK::ID).IsString())
	{
		LOG(302, GlobalK::ID, "Expected a Json String but value was wrong type: $V$﻿")
			return;
	}

	if (!InJ->Key(GlobalK::Glyph).IsNumber())
	{
		LOG(301, GlobalK::Glyph, "Expected a Json Number but value was wrong type: $V$﻿")
			return;
	}

	UID_ = InJ->ToLoadoutUID(GlobalK::UID);
	ID_ = InJ->String(GlobalK::ID);
	Glyph_ = InJ->Int(GlobalK::Glyph);

	JsonS JA = InJ->Key(LoadoutK::LoadoutAtlasi);
	int L = JA.Len();

	LOG(9513, Combo_UID_ID(), "Loadout passed check 1: $V$")
	LOG(36423, L, "Processing Atlasi Entries. Found: $V$")

	for (int i = 0; i < L; i++)
	{
		JsonS JC = JA[i];
		LoadoutAtlasC LoAtlas = LoadoutAtlasC(&JC);

		if (LoAtlas.Valid())
		{
			Atlasi_.Add(LoAtlas);
		}
	}

	LOG(27671, Combo_UID_ID(), "Loadout Is valid: $V$")

	Valid_ = true;

}

void LoadoutC::CreateMethod(int InUID, StringC InID, GlyphC InGlyph, bool InNoSave)
{
	UID_ = InUID;
	ID_ = InID;
	Glyph_ = InGlyph;
	NoSave_ = true;
	Valid_ = true;
	
}

void LoadoutC::AddAtlasLoadout(AtlasUID InUID, StringC InName)
{
	LoadoutAtlasC LoAtlas = LoadoutAtlasC(InUID,InName);
	Atlasi_.Add(LoAtlas);
}

ArrayC<AtlasUID> LoadoutC::GetSelectedAtlasi()
{
	ArrayC<AtlasUID> Selected;
	int L = Atlasi_.Len();

	for (int i = 0; i < L; i++)
	{
			Selected.Add(Atlasi_[i].UID());
	}

	return Selected;
}

StringC LoadoutC::Combo_UID_ID()
{
	return StringC(UID_.ToString() + StringC(" | ") + ID_);
}

StringC LoadoutC::ID()
{
	return ID_;
}

bool LoadoutC::IsValid()
{
	return Valid_;
}

void LoadoutC::Mount()
{

}

void LoadoutC::Dismount()
{

}

LoadoutUID LoadoutC::UID()
{
	return UID_;
}
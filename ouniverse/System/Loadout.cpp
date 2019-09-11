//Copyright 2015-2019, All Rights Reserved.

#include "System/Loadout.h"
#include "Key/GlobalK.h"
#include "Key/LoadoutK.h"
#include "Interface/Json.h"


#include "System/Log.h"


LoadoutC::LoadoutC(JsonS* InJ)
{
	Valid_ = false;

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
		LoadoutAtlasC New = LoadoutAtlasC(&JC);

		if (New.Valid())
		{
			Atlasi_.Add(New);
		}
	}

	LOG(27671, Combo_UID_ID(), "Loadout Is valid: $V$")

	Valid_ = true;

}

StringC LoadoutC::Combo_UID_ID()
{
	return StringC(UID_.ToString() + StringC(" | ") + ID_);
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



LoadoutW::LoadoutW()
{
	Loadout_ = NULL;
}

void LoadoutW::Set(LoadoutC* InLoadout)
{
	if (Loadout_!=NULL)
	{
		Loadout_->Dismount();
	}

	Loadout_ = InLoadout;
}

LoadoutC* LoadoutW::Get()
{
	return Loadout_;
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/Loadout.h"
#include "Key/GlobalK.h"
#include "Key/LoadoutK.h"
#include "Interface/Json.h"


#include "System/Log.h"


LoadoutC::LoadoutC(JsonS* InJ)
{
	Valid_ = false;

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

	UID_ = InJ->ToLoadoutUID(GlobalK::UID);
	ID_ = InJ->String(GlobalK::ID);

	JsonS JA = InJ->Key(LoadoutK::LoadoutAtlasi);
	int L = JA.Len();

	for (int i = 0; i < L; i++)
	{
		JsonS JC = JA[i];
		LoadoutAtlasC New = LoadoutAtlasC(&JC);

		if (New.Valid())
		{
			Atlasi_.Add(New);
		}
	}

	Valid_ = true;

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
	Loadout_ = nullptr;
}

void LoadoutW::Set(LoadoutC* InLoadout)
{
	if (Loadout_ != nullptr)
	{
		Loadout_->Dismount();
	}

	Loadout_ = InLoadout;

	Ev_Set.TriggerAndLife(Loadout_);
}

LoadoutC* LoadoutW::Get()
{
	return Loadout_;
}
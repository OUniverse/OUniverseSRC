//Copyright 2015-2019, All Rights Reserved.

#include "System/Loadout.h"
#include "Interface/Json.h"

#include "System/Log.h"

const char* LoadoutC::K_UID		= "u";
const char* LoadoutC::K_NAME	= "n";
const char* LoadoutC::K_ATLAS	= "a";

LoadoutC::ComboS::ComboS(JsonS* InJ)
{
	Valid_ = false;

	if(!InJ->Has(LoadoutC::K_UID))
	{ 
		LOG(300, LoadoutC::K_UID, "Missing required Json Value: $V$")
		return;
	}

	if (!InJ->Has(LoadoutC::K_NAME))
	{
		LOG(300, LoadoutC::K_NAME, "Missing required Json Value: $V$")
		return;
	}

	if (!InJ->Key(LoadoutC::K_UID).IsNumber())
	{
		LOG(301, LoadoutC::K_UID, "Expected a Json Number but value was wrong type: $V$﻿")
		return;
	}

	if (!InJ->Key(LoadoutC::K_NAME).IsString())
	{
		LOG(302, LoadoutC::K_NAME, "Expected a Json String but value was wrong type: $V$﻿")
		return;
	}

	UID_ = InJ->UInt64(LoadoutC::K_UID);
	Name_ = InJ->String(LoadoutC::K_NAME);

	Valid_ = true;
}

LoadoutC::LoadoutC(int InUID, JsonS* InJ)
{

	UID_ = InUID;


	JsonS JA = InJ->Key(LoadoutC::K_ATLAS);
	int L = JA.Len();		

	for (int i = 0; i < L; i++)
	{
		JsonS JC = JA[i];
		ComboS New = ComboS(&JC);
		if (New.Valid_)
		{
			Atlases_.Add(New);
		}
	}

}

U8 LoadoutC::GetUID()
{
	return UID_;
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutAtlas.h"
#include "Interface/Json.h"
#include "System/Log.h"

#include "Key/GlobalK.h"

LoadoutAtlasC::LoadoutAtlasC(JsonS* InJ)
{
	Valid_ = false;

	if(!InJ->Has(GlobalK::UID))
	{ 
		LOG(300, GlobalK::UID, "Missing required Json Value: $V$")
		return;
	}

	if (!InJ->Has(GlobalK::Name))
	{
		LOG(300, GlobalK::Name, "Missing required Json Value: $V$")
		return;
	}

	if (!InJ->Key(GlobalK::UID).IsNumber())
	{
		LOG(301, GlobalK::UID, "Expected a Json Number but value was wrong type: $V$﻿")
		return;
	}

	if (!InJ->Key(GlobalK::Name).IsString())
	{
		LOG(302, GlobalK::Name, "Expected a Json String but value was wrong type: $V$﻿")
		return;
	}

	UID_ = InJ->ToAtlasUID(GlobalK::UID);
	Name_ = InJ->String(GlobalK::Name);

	Valid_ = true;
}

LoadoutAtlasC::LoadoutAtlasC(AtlasUID InUID, StringC InName)
{
	UID_ = InUID;
	Name_ = InName;
	Valid_ = true;
}
AtlasUID LoadoutAtlasC::UID()
{
	return UID_;
}

StringC LoadoutAtlasC::Name()
{
	return Name_;
}

bool LoadoutAtlasC::Valid()
{
	return Valid_;
}
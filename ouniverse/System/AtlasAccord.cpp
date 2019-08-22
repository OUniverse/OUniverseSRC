//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasAccord.h"


AtlasAccordC::AtlasAccordC()
{
	long long zero = 0;
	UID_ = zero;
	Exists_ = false;
}

AtlasAccordC::AtlasAccordC(AtlasUID InUID)
{
	UID_ = InUID;
}

void AtlasAccordC::Found()
{
	Exists_ = true;
}

bool AtlasAccordC::Exists()
{
	return Exists_;
}

AtlasUID AtlasAccordC::UID()
{
	return UID_;
}
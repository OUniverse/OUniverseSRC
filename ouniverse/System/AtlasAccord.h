//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/Int.h"
#include "System/AtlasUID.h"

struct AtlasAccordC
{

	AtlasAccordC();

	AtlasAccordC(AtlasUID InUID);

	AtlasUID UID();
	void Found();
	bool Exists();

private:

	AtlasUID UID_;
	bool Exists_;

};
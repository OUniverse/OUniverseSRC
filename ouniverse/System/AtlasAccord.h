//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/Int.h"

struct AtlasAccordC
{

	AtlasAccordC();

	AtlasAccordC(U64 InUID);

	U64 UID();
	void Found();
	bool Exists();

private:

	U64 UID_;
	bool Exists_;

};
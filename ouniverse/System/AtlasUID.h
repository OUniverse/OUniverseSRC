//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"

// UINT32

class AtlasUID
{

public:

	AtlasUID();

	AtlasUID(int InInt);

	AtlasUID(StringC InS);

	int UID();

	int UID() const;

	bool operator<(const AtlasUID& l) const;

	bool operator!=(AtlasUID In);

	bool operator==(AtlasUID In);

	int ForJson();

	int ForUI();

	int ForLog();

	StringC ToString();

	int ParseTitle(StringC InFileName);


private:

	int UID_;
	
};
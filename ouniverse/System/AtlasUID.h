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

	static int Max;

	AtlasUID();

	AtlasUID(int InInt);

	AtlasUID(StringC InS);

	int UID();

	int UID() const;

	bool operator<(const AtlasUID& l) const;

	bool operator!=(AtlasUID In);

	bool operator==(AtlasUID In);

	int ToInt();

	int ForJson();

	int ForUI();

	int ForLog();

	int ParseTitle(StringC InFileName);


private:

	int UID_;
	

};
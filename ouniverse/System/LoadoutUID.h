//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"

// UINT32

class LoadoutUID
{

public:

	LoadoutUID();

	LoadoutUID(int InInt);

	LoadoutUID(StringC InS);

	int UID();

	int UID() const;

	bool operator<(const LoadoutUID& l) const;

	bool operator!=(LoadoutUID In);

	bool operator==(LoadoutUID In);

	int ForJson();

	int ForUI();

	int ForLog();

	StringC ToString();

	int ParseTitle(StringC InFileName);


private:

	int UID_;
	
};
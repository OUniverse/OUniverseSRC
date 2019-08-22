//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"

// UINT32

class SaveUID
{

public:

	SaveUID();

	SaveUID(int InInt);

	SaveUID(StringC InS);

	int UID();

	int UID() const;

	bool operator<(const SaveUID& l) const;

	bool operator!=(SaveUID In);

	bool operator==(SaveUID In);

	int ForJson();

	int ForUI();

	int ForLog();

	int ParseTitle(StringC InFileName);


private:

	int UID_;
	
};
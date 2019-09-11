//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"

// UINT32

class UserUID
{

public:

	UserUID();

	UserUID(int InInt);

	UserUID(StringC InS);

	int ToInt();

	int ToInt() const;

	bool operator<(const UserUID& l) const;

	bool operator!=(UserUID In);

	bool operator==(UserUID In);

	int ForJson();

	int ForUI();

	int ForLog();

	StringC ToString();

	int ParseTitle(StringC InFileName);


private:

	int UID_;
	
};
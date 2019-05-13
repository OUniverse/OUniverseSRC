//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "Interface/String.h"

class UserC;

class UserFileU
{

public:
	UserFileU() {};
	virtual void Save() {};
	virtual void Load() {};
	virtual ~UserFileU() {};

private:

	StringC Path;

	bool Altered_;
};
//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "Interface/String.h"

class UserFileU
{

public:
	UserFileU() {};
	UserFileU(int InUID, StringC InPath);
	virtual void Save() {};
	virtual void Load() {};
	virtual ~UserFileU() {};

private:

	int UID_;

	StringC Path_;

	bool Altered_;
};
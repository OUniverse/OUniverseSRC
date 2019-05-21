//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "Interface/String.h"

class UserDeleteC;

class SaveFileK
{

public:
	SaveFileK(StringC InPath);
	SaveFileK() {};
	virtual void Save() {};
	virtual void Load() {};
	virtual ~SaveFileK() {};

protected:

	StringC Path_;

	bool Altered_;
};
//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "Interface/String.h"


class SaveC
{

public:
	SaveC(StringC InSavePath);
	SaveC() {};
	virtual void Save() {};
	virtual void Load() {};
	virtual ~SaveC() {};

protected:

	StringC SavePath_;

	bool Altered_;
};
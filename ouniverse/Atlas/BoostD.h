//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Atlas/Doc.h"

#include "Interface/Map.h"


class BoostD : public DocD
{

public:

	static const char* EXT_Boost;
	static const char* PFX;

	BoostD(StringC InFile, StringC InPath);

	bool Valid();

	U8 UID();

private:

	U8 UID_;

	bool Valid_;

	//MapC<U32, BoostF> BoostMap;

};
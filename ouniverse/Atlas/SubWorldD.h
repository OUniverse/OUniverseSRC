//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Atlas/Doc.h"

#include "Interface/Map.h"


class SubWorldD : public DocD
{

public:

	static const char* EXT_SubWorld;
	static const char* PFX;

	SubWorldD(StringC InFile, StringC InPath);

	bool Valid();

	U8 UID();

private:

	U8 UID_;

	bool Valid_;

	//MapC<U32, SubWorldF> SubWorldMap;

};
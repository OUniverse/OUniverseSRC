//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Atlas/Doc.h"

#include "Interface/Map.h"
#include "Form/EpochF.h"

class GaiaD : public DocD
{

public:

	static const char* EXT;
	static const char* PFX;

	GaiaD(StringC InFile, StringC InPath);

	bool Valid();

	U8 UID();

private:

	U8 UID_;

	bool Valid_;

	//MapC<U32, EpochF> EpochMap;

};
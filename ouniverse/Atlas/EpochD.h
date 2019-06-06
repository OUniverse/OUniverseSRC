//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Atlas/Doc.h"

#include "Interface/Map.h"
#include "Form/EpochF.h"

class EpochD : public DocD
{

public: 

	static const char* EXT_EPOCH;
	static const char* PFX;

	EpochD(StringC InFile, StringC InPath);

	bool Valid();
	
	U8 UID();

private:

	U8 UID_;

	bool Valid_;
	
	MapC<U32, EpochF> EpochMap;

};
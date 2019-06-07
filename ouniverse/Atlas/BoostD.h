//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Atlas/Doc.h"

#include "Interface/Map.h"


class FormLibC;

class BoostD : public DocD
{

public:

	static const char* EXT;
	static const char* PFX;

	BoostD(StringC InFile, StringC InPath);

	bool Valid();

	U8 UID();

	void Mount(FormLibC* InFormLib);

private:

	U8 UID_;

	bool Valid_;

	//MapC<U32, BoostF> BoostMap;

};
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

	static const char* FILE_NAME;

	BoostD(StringC InPath, StringC InLogID);

	bool Valid();

	StringC GetForms();

private:

	bool Valid_;

};
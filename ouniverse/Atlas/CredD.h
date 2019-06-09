//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Atlas/Doc.h"

#include "Interface/Map.h"


class CredD : public DocD
{

public:

	static const char* FILE_NAME;

	CredD(StringC InPath, StringC InLogID);

	bool Valid();

private:

	bool Valid_;

};
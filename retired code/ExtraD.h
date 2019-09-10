//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Atlas/Doc.h"

#include "Interface/Map.h"


class FormLibC;

class ExtraD : public DocD
{

public:

	static const char* FILE_NAME;

	ExtraD(StringC InPath, StringC InLogID);

	bool Valid();

	void Mount(FormLibC* InFormLib);

private:

	bool Valid_;

};
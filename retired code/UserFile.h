//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "Interface/String.h"


class UserFileC : public SaveC
{
	static const char* K_NAME;
	static const char* K_GLYPH;
	static const char* K_AWARDS;
	static const char* FILE_NAME;

public:

	UserFileC(StringC InPath);

	StringC Name_;
	StringC Glyph_;

	bool Valid();

private:

	bool Valid_;
};
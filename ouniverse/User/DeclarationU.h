//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "User/UserFileU.h"

class DeclarationU : public UserFileU
{

public:

	DeclarationU(StringC RootPath, int InUID);

	int UID_;

	StringC Name;
	StringC Glyph;
};
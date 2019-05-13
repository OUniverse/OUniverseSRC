//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "User/UserFileU.h"

class DeclarationU : public UserFileU
{

public:

	DeclarationU() {};
	DeclarationU(int InUID, StringC InPath);

	int UID;
	StringC Path;

	StringC Name;
	StringC Glyph;
};
//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "User/UserFileU.h"
#include "Interface/String.h"

class RecordsU : public UserFileU
{

public:

	RecordsU(StringC RootPath);

	int UID;
};
//Copyright 2015-2019, All Rights Reserved.

/**

 */

#pragma once

#include "Kernel/SaveFileK.h"


class SaveBriefK : public SaveFileK
{

public:

	SaveBriefK(StringC RootPath);

	
	bool IsValid();
	
};
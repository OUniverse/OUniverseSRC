//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/String.h"

struct DirS
{

	DirS(StringC InPath);	

	StringC Get();
	
	DirS* Tier(const char* In);

	StringC File(StringC FileName);

	void Make();

private:

	StringC Path_;
};
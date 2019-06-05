//Copyright 2015-2019, All Rights Reserved.

#include "Data/Life.h"


bool LifeD::Extension(StringC InExtension)
{
	if (InExtension == StringC("atlas"))
	{
		return true;
	}
	return false;
}
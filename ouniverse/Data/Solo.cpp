//Copyright 2015-2019, All Rights Reserved.

#include "Data/Solo.h"


bool SoloD::Extension(StringC InExtension)
{
	if (InExtension == StringC("atlas"))
	{
		return true;
	}
	return false;
}
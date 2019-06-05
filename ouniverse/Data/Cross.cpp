//Copyright 2015-2019, All Rights Reserved.

#include "Data/Cross.h"


bool CrossD::Extension(StringC InExtension)
{
	if (InExtension == StringC("atlas"))
	{
		return true;
	}
	return false;
}
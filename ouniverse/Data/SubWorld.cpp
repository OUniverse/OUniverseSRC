//Copyright 2015-2019, All Rights Reserved.

#include "Data/SubWorld.h"


bool SubWorldD::Extension(StringC InExtension)
{
	if (InExtension == StringC("atlas"))
	{
		return true;
	}
	return false;
}
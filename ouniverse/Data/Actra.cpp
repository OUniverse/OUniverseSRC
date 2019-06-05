//Copyright 2015-2019, All Rights Reserved.

#include "Data/Actra.h"


bool ActraD::Extension(StringC InExtension)
{
	if (InExtension == StringC("atlas"))
	{
		return true;
	}
	return false;
}
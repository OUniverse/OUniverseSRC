//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Int.h"
#include  <limits>

bool Int::Is32U(int N)
{
	if (N > USHRT_MAX || N <= -1)
	{
		return false;
	}

	return true;

} 
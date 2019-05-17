//Copyright 2015-2019, All Rights Reserved.

#include "System/Terra.h"

namespace GlobalSingleton
{
	TerraC Terra;
}

TerraC* TerraC::Get()
{
	return &GlobalSingleton::Terra;
}

TerraC* TerraC::Create()
{
	GlobalSingleton::Terra = *(new TerraC());
	return &GlobalSingleton::Terra;
}

TerraC::TerraC()
{

}
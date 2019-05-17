//Copyright 2015-2019, All Rights Reserved.

#include "System/Terra.h"


namespace GlobalSingleton
{
	TerraC Cosmos;
}

TerraC* TerraC::Get()
{
	return &GlobalSingleton::Cosmos;
}

TerraC* TerraC::Create()
{
	GlobalSingleton::Cosmos = *(new TerraC());
	return &GlobalSingleton::Cosmos;
}

TerraC::TerraC()
{

}
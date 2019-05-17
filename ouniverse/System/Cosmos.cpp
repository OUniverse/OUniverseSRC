//Copyright 2015-2019, All Rights Reserved.

#include "System/Cosmos.h"


namespace GlobalSingleton
{
	CosmosC Cosmos;
}

CosmosC* CosmosC::Get()
{
	return &GlobalSingleton::Cosmos;
}

CosmosC* CosmosC::Create()
{
	GlobalSingleton::Cosmos = *(new CosmosC());
	return &GlobalSingleton::Cosmos;
}

CosmosC::CosmosC()
{

}
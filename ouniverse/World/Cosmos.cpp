//Copyright 2015-2019, All Rights Reserved.

#include "World/Cosmos.h"



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
	//ACosm* NewLevel = Major->GetWorld()->SpawnActor<ACosm>(ACosm::StaticClass());
//NewLevel->Infuse(Major->GetData("ou.c_areaTest"));
//LoadedCosms.Emplace(NewLevel);
//NewLevel->NewLevel();
}
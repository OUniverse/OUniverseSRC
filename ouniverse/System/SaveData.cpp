//Copyright 2015-2019, All Rights Reserved.

#include "System/Cosmos.h"

#include "System/Ether.h"
#include "Min/MajorM.h"


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

void CosmosC::Mount()
{
	NewLevel();
}

void CosmosC::FauxMount()
{
	NewLevel();
}

void CosmosC::Dismount()
{

}


void CosmosC::NewLevel()
{
	MAJOR->Party();
	MAJOR->Ether()->StreamLevel("TESTMAP");
}

void CosmosC::NewLevelLoaded()
{
	//FVector Location(0.0f, 0.0f, 0.0f);
	//FRotator Rotation(0.0f, 0.0f, 0.0f);
	//FActorSpawnParameters SpawnInfo;
	//MAJOR->Scope()->SpawnActor<ACharacterUE>(Location, Rotation, SpawnInfo);
}
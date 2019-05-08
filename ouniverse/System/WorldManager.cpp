//Copyright 2015-2019, All Rights Reserved.

#include "WorldManager.h"
#include "System/Major.h"
#include "Cosm.h"

void UWorldManager::Init(UMajor* InMajor)
{
	Major = InMajor;
}

void UWorldManager::TravelToWorld()
{
	ACosm* NewLevel = Major->GetWorld()->SpawnActor<ACosm>(ACosm::StaticClass());
	NewLevel->Infuse(Major->GetData("ou.c_areaTest"));
	LoadedCosms.Emplace(NewLevel);
	NewLevel->NewLevel();
}
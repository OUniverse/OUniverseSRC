//Copyright 2015-2019, All Rights Reserved.

#include "Cosm.h"
#include "System/Major.h"
#include "Data/Data.h"

ACosm::ACosm()
{

}



void ACosm::Infuse(Data* InData)
{
	Gene = static_cast<D_Area*>(InData);
}


void ACosm::NewLevel()
{
	bool bFound = true;
	LevelStreamed = ULevelStreamingDynamic::LoadLevelInstance(this, Gene->MapID, FVector(0.0f), FRotator(0.0f), bFound);
	//LevelStreamed->OnLevelLoaded.AddDynamic(this, &ACosm::MapLoaded);

}

void ACosm::MapLoaded()
{


	//int32 RefCount = GENE->Refs.Num();
	//AActra* TempRef;
	//for (int i = 0; i < RefCount; i++)
	//{
	//	TempRef = GetWorld()->SpawnActor<AActra>(AActra::StaticClass());
	//	TempRef->InitGENE(FDat(GENE->Major, "ou.5001").Data);
	//	TempRef->Construct();
	//	TempRef->SetActorTransform(GENE->Refs[i]->Transforms);
	//}
}
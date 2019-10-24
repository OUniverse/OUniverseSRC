//Copyright 2015-2019, All Rights Reserved.

#include "System/SpaceUE.h"
#include "System/Ether.h"

#include "System/CharacterUE.h"
#include "System/CameraUE.h"

#include "Engine/World.h"

USpaceUE::USpaceUE()
{

}

void USpaceUE::Init(EtherC* InEther, UObject* InWorldContext, UWorld* InScope)
{
	Ether_ = InEther;
	WorldContext_ = InWorldContext;
	Scope_ = InScope;
}
void USpaceUE::StreamLevel(StringC InLevelID)
{
	bool bFound = true;
	StreamedLevel_ = ULevelStreamingDynamic::LoadLevelInstance(WorldContext_, InLevelID.ToChar(), FVector(0.0f), FRotator(0.0f), bFound);
	StreamedLevel_->OnLevelLoaded.AddDynamic(this, &USpaceUE::OnLevelStreamed);
}

void USpaceUE::OnLevelStreamed()
{
	Ether_->OnLevelStreamed();
}

ACharacterUE* USpaceUE::Spawn()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	return Scope_->SpawnActor<ACharacterUE>(Location, Rotation);
}

ACameraUE* USpaceUE::SpawnCamera()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	return Scope_->SpawnActor<ACameraUE>(Location, Rotation);
}
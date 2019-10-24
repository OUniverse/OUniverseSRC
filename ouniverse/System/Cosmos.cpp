//Copyright 2015-2019, All Rights Reserved.

#include "System/Cosmos.h"
#include "Min/MajorM.h"
#include "Engine/World.h"

#include "System/ControlUE.h"
#include "System/CharacterUE.h"
#include "System/CameraUE.h"
#include "Component/DollyControl.h"

#include "Actual/ActorA.h"



void UCosmos::Init(AControlUE* InControl, UObject* InWorldContext, UWorld* InScope)
{
	Control_ = InControl;
	WorldContext_ = InWorldContext;
	Scope_ = InScope;
}

void UCosmos::Mount()
{

}

void UCosmos::Dismount()
{

}

void UCosmos::LoadLevel(StringC LevelName)
{
	bool bFound = true;
	StreamedLevel_ = ULevelStreamingDynamic::LoadLevelInstance(WorldContext_, LevelName.ToChar(), FVector(0.0f), FRotator(0.0f), bFound);
	StreamedLevel_->OnLevelLoaded.AddDynamic(this, &UCosmos::OnLevelStreamed);
}
void UCosmos::OnLevelStreamed()
{

}

void UCosmos::SpawnParty(ArrayC<ActorA*> InPartyActors)
{
	SpawnCharacter(InPartyActors[0]);
}

ACharacterUE* UCosmos::SpawnCharacter(ActorA* InActor)
{
	TSoftClassPtr<ACharacterUE> CharacterClass = TSoftClassPtr<ACharacterUE>(FSoftClassPath("/Game/bp/system/character.character_C"));
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	ACharacterUE* NewActor = Scope_->SpawnActor<ACharacterUE>(CharacterClass.LoadSynchronous(),Location, Rotation);
	InActor->Mount(NewActor);
	return NewActor;
}

ACameraUE* UCosmos::SpawnCamera()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	return Scope_->SpawnActor<ACameraUE>(Location, Rotation);
}
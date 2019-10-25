//Copyright 2015-2019, All Rights Reserved.

#include "System/Cosmos.h"
#include "Min/MajorM.h"
#include "Engine/World.h"

#include "System/ControlUE.h"
#include "Form/Character3D.h"
#include "System/CameraUE.h"
#include "Component/DollyControl.h"

#include "Form/ActorA.h"


namespace Global
{
	UCosmos* Cosmos;
}

UCosmos::UCosmos() {};

UCosmos* UCosmos::Create(AControlUE* InControl, UObject* InWorldContext, UWorld* InScope)
{
	UCosmos* Obj = NewObject<UCosmos>();
	Obj->Init(InControl,InWorldContext,InScope);
	Global::Cosmos = Obj;
	return Obj;
}

UCosmos* UCosmos::Get()
{
	return Global::Cosmos;
}

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

UWorld* UCosmos::Scope()
{
	return Scope_;
}

bool UCosmos::RegisterSpawn(AActor* InAct)
{
	if (!InAct)
	{
		FGenericPlatformMisc::RequestExit(true);
		return false;
	}

	return true;
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

ACharacter3D* UCosmos::SpawnCharacter(ActorA* InActor)
{
	TSoftClassPtr<ACharacter3D> CharacterClass = TSoftClassPtr<ACharacter3D>(FSoftClassPath(ACharacter3D::Class));
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	ACharacter3D* NewActor = Scope_->SpawnActor<ACharacter3D>(CharacterClass.LoadSynchronous(),Location, Rotation);
	if (!NewActor)
	{
		FGenericPlatformMisc::RequestExit(true);
	}
	InActor->Mount(NewActor);
	return NewActor;
}

ACameraUE* UCosmos::SpawnCamera()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	return Scope_->SpawnActor<ACameraUE>(Location, Rotation);
}
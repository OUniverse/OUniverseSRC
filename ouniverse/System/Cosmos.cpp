//Copyright 2015-2019, All Rights Reserved.

#include "System/Cosmos.h"
#include "System/Scope.h"
#include "Engine/World.h"

#include "System/ControlUE.h"
#include "Form/Character3D.h"
#include "System/CameraUE.h"
#include "Component/DollyControl.h"


namespace Global
{
	UCosmos* Cosmos;
}

UCosmos::UCosmos() {};

UCosmos* UCosmos::Create(AControlUE* InControl)
{
	UCosmos* Neu = NewObject<UCosmos>();
	Neu->Init(InControl);
	Global::Cosmos = Neu;
	return Neu;
}

UCosmos* UCosmos::Get()
{
	return Global::Cosmos;
}

void UCosmos::Init(AControlUE* InControl)
{
	Control_ = InControl;
}

void UCosmos::Mount()
{

}

void UCosmos::Dismount()
{

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
	StreamedLevel_ = ULevelStreamingDynamic::LoadLevelInstance(ScopeC::WorldContext(), LevelName.ToChar(), FVector(0.0f), FRotator(0.0f), bFound);
	StreamedLevel_->OnLevelLoaded.AddDynamic(this, &UCosmos::OnLevelStreamed);
}
void UCosmos::OnLevelStreamed()
{

}

ACameraUE* UCosmos::SpawnCamera()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	return ScopeC::World()->SpawnActor<ACameraUE>(Location, Rotation);
}
//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/WorldP.h"
#include "System/Cosmos.h"
#include "System/ControlUE.h"
#include "System/Party.h"

#include "Actual/ActorA.h"
#include "System/CharacterUE.h"
#include "System/CameraUE.h"
#include "Min/DebugM.h"

WorldP::WorldP(AControlUE* InControl, UCosmos* InCosmos)
{
	Cosmos_ = InCosmos;
	Control_ = InControl;

	Party_ = new PartyC();
}

void WorldP::Start()
{
	Cosmos_->LoadLevel(StringC("TESTMAP"));
	Party_->Faux();
	Cosmos_->SpawnParty(Party_->GetActors());
	Possess(Party_->Member(0));
};

void WorldP::Possess(ActorA* InActor)
{
	Control_->GetCamera()->SetGoal(InActor->GetCharacterUE()->GetControlCam());
}
InputReplyS WorldP::Forward(InputActionS InIA)
{
	DBUG("FORWARD GO GO GO GO ")
	return true;
}


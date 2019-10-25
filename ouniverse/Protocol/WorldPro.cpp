//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/WorldPro.h"
#include "System/Cosmos.h"
#include "System/ControlUE.h"
#include "System/Party.h"

#include "Form/ActorA.h"
#include "Form/Character3D.h"
#include "System/CameraUE.h"
#include "Min/DebugM.h"


UWorldPro::UWorldPro() : UProtocol()
{

}

UWorldPro* UWorldPro::Create(AControlUE* InControl, UCosmos* InCosmos)
{
	UWorldPro* Obj = NewObject<UWorldPro>();
	Obj->Init(InControl,InCosmos);
	return Obj;
}

void UWorldPro::Init(AControlUE* InControl, UCosmos* InCosmos)
{
	Cosmos_ = InCosmos;
	Control_ = InControl;
	Party_ = UParty::Create();
}

void UWorldPro::Start()
{
	Cosmos_->LoadLevel(StringC("TESTMAP"));
	Party_->Faux();
	//Cosmos_->SpawnParty(Party_->GetActors());
	//Possess(Party_->Member(0));
};

void UWorldPro::Possess(ActorA* InActor)
{
	Control_->GetCamera()->SetGoal(InActor->M3D()->GetControlCam());
	InActor->M3D()->Possess();
}

InputReplyS UWorldPro::Forward(InputActionS InIA)
{
	DBUG("FORWARD GO GO GO GO ")
	return true;
}


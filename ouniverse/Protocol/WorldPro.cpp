//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/WorldPro.h"
#include "System/Cosmos.h"
#include "System/ControlUE.h"
#include "System/Party.h"

#include "Form/CharacterA.h"
#include "Form/Character3D.h"
#include "System/CameraUE.h"
#include "Min/DebugM.h"


WorldProC::WorldProC(int InID, MaestroC* InMaestro, AControlUE* InControl, UCosmos* InCosmos) : ProtocolC(InID,this)
{
	Cosmos_ = InCosmos;
	Control_ = InControl;
	Party_ = UParty::Create();
	//Populace_ = PopulaceC::Create();
	CharacterInputBeacon_ = NewObject<UInputSchemaCharacter>();
}

WorldProC* WorldProC::Create(int InID, MaestroC* InMaestro, AControlUE* InControl, UCosmos* InCosmos)
{
	WorldProC* Obj = new WorldProC(InID, InMaestro,InControl,InCosmos);
	return Obj;
}


void WorldProC::Start()
{
	Cosmos_->LoadLevel(StringC("TESTMAP"));
	Party_->Faux();
	Party_->Spawn();

	Possess(Party_->Members_[0]);
};

void WorldProC::Possess(UCharacterA* InChar)
{
	CharacterInputBeacon_->SetCharacter(InChar);
	//AddInputSchema(CharacterInputBeacon_);
	PossessedCharacter_ = InChar;
	InChar->Possess();
	Control_->GetCamera()->SetGoal(InChar->Character3D()->GetControlCam());
	Control_->Possess(InChar->Character3D());

}

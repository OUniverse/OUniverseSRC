//Copyright 2015-2019, All Rights Reserved.

#include "System/Party.h"
#include "Form/CharacterD.h"
#include "Form/CharacterE.h"

UParty::UParty() {}

UParty* UParty::Create()
{
	UParty* Obj = NewObject<UParty>();
	Obj->Init();
	return Obj;
}

void UParty::Init()
{
	
}

void UParty::Faux()
{
	Player_ = (new CharacterD())->CreateEx();
}

void UParty::Spawn()
{
	Player_->Spawn();
}
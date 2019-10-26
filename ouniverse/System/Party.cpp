//Copyright 2015-2019, All Rights Reserved.

#include "System/Party.h"
#include "Form/CharacterF.h"
#include "Form/CharacterE.h"
#include "Interface/Data.h"

#include "Min/DebugM.h"

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
	DataC Dat = DataC(DuetUID(2147483647, 55));
	CharacterF* Character = static_cast<CharacterF*>(Dat.Form());
	Player_ = Character->CreateEx();
}

void UParty::Spawn()
{
	Player_->Spawn();
}
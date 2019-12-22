//Copyright 2015-2019, All Rights Reserved.

#include "System/Party.h"
#include "Data/CharacterD.h"
#include "Form/CharacterA.h"
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
	DataC Dat = DataC(DuetUID(1, 55));
	CharacterD* Character = static_cast<CharacterD*>(Dat.Form());	
	Members_.Emplace(Character->CreateEx());

	Dat = DataC(DuetUID(1, 56));
	Character = static_cast<CharacterD*>(Dat.Form());
	Members_.Emplace(Character->CreateEx());
}

void UParty::Spawn()
{
	Members_[0]->Spawn();
	Members_[1]->Spawn();
}
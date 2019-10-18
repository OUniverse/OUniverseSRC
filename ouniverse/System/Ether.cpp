//Copyright 2015-2019, All Rights Reserved.

#include "System/Ether.h"
#include "System/SpaceUE.h"
#include "System/CharacterUE.h"

namespace GlobalSingleton
{
	EtherC Ether;
}

EtherC* EtherC::Get()
{
	return &GlobalSingleton::Ether;
}

EtherC* EtherC::Create(UObject* InWorldContext, UWorld* InScope)
{
	GlobalSingleton::Ether = *(new EtherC(InWorldContext,InScope));
	return &GlobalSingleton::Ether;
}

EtherC::EtherC(UObject* InWorldContext, UWorld* InScope)
{
	Space_ = NewObject<USpaceUE>();
	Space_->Init(this,InWorldContext,InScope);
}

void EtherC::StreamLevel(StringC InLevelID)
{
	Space_->StreamLevel(InLevelID);
}

void EtherC::OnLevelStreamed()
{

}

ACharacterUE* EtherC::Spawn()
{
	return Space_->Spawn();
}

ACameraUE* EtherC::SpawnCamera()
{
	return Space_->SpawnCamera();
}
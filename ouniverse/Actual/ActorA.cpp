//Copyright 2015-2019, All Rights Reserved.

#include "Actual/ActorA.h"

#include "System/CharacterUE.h"
#include "Min/MajorM.h"

ActorA::ActorA() : ObjectA()
{

}

void ActorA::Mount(ACharacterUE* InCharacter)
{
	CharacterUE_ = InCharacter;
}

void ActorA::Dismount()
{

}

ACharacterUE* ActorA::GetCharacterUE()
{
	return CharacterUE_;
}
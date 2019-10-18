//Copyright 2015-2019, All Rights Reserved.

#include "Actual/ActorA.h"

#include "System/CharacterUE.h"
#include "System/Ether.h"

#include "Min/MajorM.h"

ActorA::ActorA() : ObjectA()
{

}

void ActorA::Spawn()
{
	CharacterUE_ = MAJOR->Ether()->Spawn();
}
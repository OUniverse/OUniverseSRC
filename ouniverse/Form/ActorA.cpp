//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActorA.h"

#include "Form/Character3D.h"
#include "Min/MajorM.h"

ActorA::ActorA() : ObjectA()
{

}

void ActorA::Mount(ACharacter3D* InCharacter)
{
	M3D_ = InCharacter;
}

void ActorA::Dismount()
{

}

ACharacter3D* ActorA::M3D()
{
	return M3D_;
}
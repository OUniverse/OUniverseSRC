//Copyright 2015-2019, All Rights Reserved.

#include "System/Party.h"
#include "Actual/ActorA.h"

PartyC::PartyC()
{

}

void PartyC::Faux()
{
	Members_.Add(new ActorA());
}

ActorA* PartyC::Member(int index)
{
	return Members_[index];
}

ArrayC<ActorA*> PartyC::GetActors()
{
	return Members_;
}
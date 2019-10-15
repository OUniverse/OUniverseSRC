//Copyright 2015-2019, All Rights Reserved.

#include "System/Party.h"

namespace GlobalSingleton
{
	PartyC Party;
}

PartyC* PartyC::Get()
{
	return &GlobalSingleton::Party;
}

PartyC* PartyC::Create()
{
	GlobalSingleton::Party = *(new PartyC());
	return &GlobalSingleton::Party;
}

PartyC::PartyC()
{

}
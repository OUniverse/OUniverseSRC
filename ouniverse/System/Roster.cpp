//Copyright 2015-2019, All Rights Reserved.

#include "System/Roster.h"

namespace GlobalSingleton
{
	RosterC Roster;
}

RosterC* RosterC::Get()
{
	return &GlobalSingleton::Roster;
}

RosterC* RosterC::Create()
{
	GlobalSingleton::Roster = *(new RosterC());
	return &GlobalSingleton::Roster;
}

RosterC::RosterC()
{

}
//Copyright 2015-2019, All Rights Reserved.

#include "System/Scope.h"


namespace Global
{
	UWorld* World;
	UObject* WorldContextObject;
}

ScopeC::ScopeC(UObject* InWorldContextObject, UWorld* InWorld)
{
	Global::WorldContextObject = InWorldContextObject;
	Global::World = InWorld;
}

UWorld* ScopeC::World()
{
	return Global::World;
}

UObject* ScopeC::WorldContext()
{
	return Global::WorldContextObject;
}
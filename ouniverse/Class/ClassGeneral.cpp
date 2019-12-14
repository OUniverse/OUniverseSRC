//Copyright 2015-2019, All Rights Reserved.

#include "Class/ClassGeneral.h"
#include "System/Scope.h"

namespace Class
{
	UClassGeneral* General;
}

void UClassGeneral::Initialize()
{
	TSubclassOf<UClassGeneral> Classer = TSoftClassPtr<UClassGeneral>(FSoftClassPath("/Game/class/ClassGeneral.ClassGeneral_C")).LoadSynchronous();
	Class::General = NewObject<UClassGeneral>(ScopeC::WorldContext(),*Classer);
}

UClassGeneral* UClassGeneral::Get()
{
	return Class::General;
}
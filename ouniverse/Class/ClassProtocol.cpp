//Copyright 2015-2019, All Rights Reserved.

#include "Class/ClassProtocol.h"
#include "System/Scope.h"

namespace Class
{
	UClassProtocol* Protocol;
}


void UClassProtocol::Initialize()
{
	TSubclassOf<UClassProtocol> Classer = TSoftClassPtr<UClassProtocol>(FSoftClassPath("/Game/class/ClassProtocol.ClassProtocol_C")).LoadSynchronous();
	Class::Protocol = NewObject<UClassProtocol>(ScopeC::WorldContext(),*Classer);
}

UClassProtocol* UClassProtocol::Get()
{
	return Class::Protocol;
}
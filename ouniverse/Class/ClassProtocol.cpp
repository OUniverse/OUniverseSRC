//Copyright 2015-2019, All Rights Reserved.

#include "Class/ClassProtocol.h"
#include "System/Scope.h"

#include "Min/DebugM.h"

namespace Class
{
	UClassProtocol* Protocol;
}


void UClassProtocol::Initialize()
{
	TSubclassOf<UClassProtocol> Classer = TSoftClassPtr<UClassProtocol>(FSoftClassPath("/Game/class/ClassProtocol.ClassProtocol_C")).LoadSynchronous();
	Class::Protocol = NewObject<UClassProtocol>(ScopeC::WorldContext(),*Classer);
	DBUG("INITIALIZED")
}

UClassProtocol* UClassProtocol::Get()
{
	return Class::Protocol;
}
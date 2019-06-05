//Copyright 2015-2019, All Rights Reserved.

#include "System/ProtocolManager.h"
#include "Protocol/UserP.h"
#include "Protocol/SystemP.h"
#include "Protocol/OpenWorldP.h"
#include "System/Major.h"


ProtocolManager* ProtocolManager::Create(MajorC* Major)
{
	return new ProtocolManager(Major);
}


ProtocolManager::ProtocolManager(MajorC* Major)
{

	Map_.Init(Types::MAX, NULL);
	Map_[Types::User] = new UserP(Major->Kernel(),Major->UserL());
	Map_[Types::System] = new SystemP();
	Map_[Types::OpenWorld] = new OpenWorldP();
}

ProtocolP* ProtocolManager::GetProtocol(Types Type)
{
	return Map_[Type];
}

ProtocolP* ProtocolManager::Activate(Types Type)
{
	ProtocolP* ActivatedProtocol = GetProtocol(Type);
	ActivatedProtocol->Activate();
	return ActivatedProtocol;
}



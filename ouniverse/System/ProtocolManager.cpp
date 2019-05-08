//Copyright 2015-2019, All Rights Reserved.

#include "System/ProtocolManager.h"
#include "System/Major.h"
#include "System/UserManager.h"
#include "System/User.h"
#include "System/DataManager.h"
#include "System/WorldManager.h"
#include "Protocol/Protocol.h"
#include "Protocol/Protocol_User.h"
#include "Protocol/Protocol_Title.h"
#include "System/LogMinimal.h"

UProtocolManager::UProtocolManager()
{

}

void UProtocolManager::Init(UMajor* InMajor)
{
	Major = InMajor;
	UProtocol* User = NewObject<UProtocol_User>();
	User->Init(Major);
	UProtocol* Title = NewObject<UProtocol_Title>();
	Title->Init(Major);
	ProtocolMap.Add(EProtocol::User, User);
	ProtocolMap.Add(EProtocol::Title, Title);
	LOG(LBOOT, 1, "ProtocolManager: On");
}

UProtocol* UProtocolManager::GetProtocol(EProtocol ProtocolType)
{
	return ProtocolMap.FindRef(ProtocolType);
}

UProtocol* UProtocolManager::Activate(EProtocol ProtocolType)
{
	UProtocol* ActivatedProtocol = GetProtocol(ProtocolType);
	ActivatedProtocol->Activate();
	return ActivatedProtocol;
}
//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Protocol_User.h"
#include "System/Major.h"
#include "System/UiManager.h"
#include "UI/I_User.h"
#include "System/User.h"
#include "System/UserManager.h"
#include "System/ProtocolManager.h"
#include "System/LogMinimal.h"

void UProtocol_User::Activate()
{
	LOG(LBOOT,1,"Protocol_User.cpp | UProtocol_User::Activate | Activating Protocol: User Select");
	Major->UserManager->GetAllUsers();
	Major->UiManager->I_User->Activate();
	Major->UiManager->I_User->King();

	//>I> Bypass selection if only one user is found.
	//>I> Show User Description and enter creation mode if no user is found.
	//?Q? If only one user data is found should it auto selected and selection bypassed?
	//?Q? Begin selection on previously used User?



	//Major->DataManager->LoadData();
	//Major->WorldManager->TravelToWorld();






}

void UProtocol_User::UserSelected()
{
	Major->ProtocolManager->Activate(EProtocol::Title);
}

//Copyright 2015-2019, All Rights Reserved.

#include "State/SystemMenuS.h"
#include "System/UiManager.h"
#include "System/UserLib.h"
#include "UI/SystemMenuI.h"

SystemMenuState::SystemMenuState(UiC* InUi, UserLib* InUser)
{
	UiP = InUi;
	UserP = InUser;
}

void SystemMenuState::Activate()
{
	//LOG(LBOOT,1,"Protocol Activated: SystemMenu");
	//UserP->GetAllUsers();
	//UiP->IoSystemMenu()->King();

	//Major->DataManager->LoadData();
	//Major->WorldManager->TravelToWorld();
}
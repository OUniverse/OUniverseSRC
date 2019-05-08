//Copyright 2015-2019, All Rights Reserved.

#include "Mode.h"
#include "System/DisplayManager.h"
#include "GameFramework/PlayerController.h"

AMode::AMode()
{
	//PlayerControllerClass = 
	HUDClass = ADisplayManager::StaticClass();
}

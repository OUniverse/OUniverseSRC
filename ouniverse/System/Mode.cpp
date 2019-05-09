//Copyright 2015-2019, All Rights Reserved.

#include "Mode.h"
#include "System/HudUE.h"
#include "System/ControlUE.h"

AMode::AMode()
{
	//PlayerControllerClass = 
	HUDClass = AHudUE::StaticClass();
	PlayerControllerClass = AControlUE::StaticClass();
}

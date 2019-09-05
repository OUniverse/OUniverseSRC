//Copyright 2015-2019, All Rights Reserved.

#include "System/ConfigManager.h"
#include "Interface/Ini.h"
#include "Interface/Dir.h"
#include "Min/DebugM.h"

ConfigManager::ConfigManager(OniManagerC* InOni)
{
	Oni_ = InOni;
}
//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - Settings
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"


class OUNIVERSE_API SettingsISM : public IoSM
{
	friend SystemMenuIO;

private:

	SettingsISM(GlassC* InGlass, SystemMenuIO* InSymu);
	
	void Activate() override;
	void King() override;
};
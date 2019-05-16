//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - Title
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"


class OUNIVERSE_API CreditsISM : public IoSM
{
	friend SystemMenuIO;

private:

	CreditsISM(GlassC* InGlass, SystemMenuIO* InSymu);
	
	void Activate() override;
	void King() override;
};
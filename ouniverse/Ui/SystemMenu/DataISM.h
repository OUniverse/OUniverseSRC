//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - Data
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"


class OUNIVERSE_API DataISM : public IoSM
{
	friend SystemMenuIO;

private:

	DataISM(GlassC* InGlass, SystemMenuIO* InSymu);
	
	void Activate() override;
	void King() override;
};
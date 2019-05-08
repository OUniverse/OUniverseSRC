//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - News
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"


class OUNIVERSE_API NewsISM : public IoSM
{
	friend SystemMenuIO;

private:

	NewsISM(UCohtmlHUD* InUi, SystemMenuIO* InSymu);
	
	void Activate() override;
	void King() override;
};
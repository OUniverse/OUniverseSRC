//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - Instance
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"


class OUNIVERSE_API PlaythroughISM : public IoSM
{
	friend SystemMenuIO;

private:

	PlaythroughISM(UCohtmlHUD* InUi, SystemMenuIO* InSymu);

	void Activate() override;
	void King() override;
};
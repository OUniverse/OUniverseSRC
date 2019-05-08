//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - Details
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"


class OUNIVERSE_API DetailsISM : public IoSM
{
	friend SystemMenuIO;

private:

	DetailsISM(UCohtmlHUD* InUi, SystemMenuIO* InSymu);
	
	void Activate() override;
	void King() override;
};
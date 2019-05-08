//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - Title
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"


class OUNIVERSE_API TitleISM : public IoSM
{
	friend SystemMenuIO;

private:

	TitleISM(UCohtmlHUD* InUi, SystemMenuIO* InSymu);
	
	void Activate() override;
	void King() override;
	
};
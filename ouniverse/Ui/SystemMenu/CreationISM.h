//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - Creation
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"

class IoSM;


class OUNIVERSE_API CreationISM : public IoSM
{

	friend SystemMenuIO;

private:

	CreationISM(UCohtmlHUD* InUi, SystemMenuIO* InSymu);

	void Activate() override;
	void King() override;		

};
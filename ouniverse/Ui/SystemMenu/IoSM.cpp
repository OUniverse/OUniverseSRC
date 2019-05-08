//Copyright 2015-2019, All Rights Reserved.

#include "Ui/SystemMenu/IoSM.h"
#include "Ui/Io.h"
#include "Ui/SystemMenuI.h"
#include "CohtmlHUD.h"


IoSM::IoSM(UCohtmlHUD* InUi, SystemMenuIO* InSyMenu) : Io(InUi)
{
	SystemMenuP = InSyMenu;
}
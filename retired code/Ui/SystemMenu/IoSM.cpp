//Copyright 2015-2019, All Rights Reserved.

#include "Ui/SystemMenu/IoSM.h"
#include "Ui/Io.h"
#include "Ui/SystemMenuI.h"
#include "System/Glass.h"


IoSM::IoSM(GlassC* InGlass, SystemMenuIO* InSyMenu) : Io(InGlass)
{
	SystemMenuP = InSyMenu;
}
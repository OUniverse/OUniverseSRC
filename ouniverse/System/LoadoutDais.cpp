//Copyright 2015-2019, All Rights Reserved.

#include "System/LoadoutDais.h"
#include "System/Loadout.h"
#include "System/SaveLib.h"
#include "System/UserDais.h"


#include "Min/DebugM.h"

LoadoutDaisC::LoadoutDaisC()
{
	Loadout_ = NULL;
}

void LoadoutDaisC::Set(LoadoutC* InLoadout)
{
	if (Loadout_!=NULL)
	{
		Loadout_->Dismount();
	}

	Loadout_ = InLoadout;
}

LoadoutC* LoadoutDaisC::Get()
{
	return Loadout_;
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/SaveDais.h"
#include "System/Save.h"

SaveDaisC::SaveDaisC()
{
	Save_ = nullptr;
}

void SaveDaisC::Set(SaveC* InSave)
{
	if (Save_ != nullptr)
	{
		Save_->Dismount();
	}

	Save_ = InSave;
	E_Set.TriggerAndLife(Save_);
}

SaveC* SaveDaisC::Get()
{
	return Save_;
}
//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Focal.h"
#include "Protocol/Focus.h"

FocalC::FocalC()
{
	FocalActive_ = NULL;
}

FocusC* FocalC::RegisterFocus(FocusC* InFocus)
{
	Foci_.Add(InFocus->ID(),InFocus);
	return InFocus;
}

void FocalC::FocalActivate(int InID)
{
	if (FocalActive_ != NULL)
	{
		FocalActive_->Unfocus();
	}
	FocalActive_ = Foci_.Find(InID);
	FocalActive_->Focus();
}

void FocalC::FocalTrigger(int ID, int InDir)
{
	Foci_.Find(ID)->Call(InDir);
}

bool FocalC::FocalInputCommand(KeyS InKey)
{
	return FocalActive_->InputCommand(InKey);
}
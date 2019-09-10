//Copyright 2015-2019, All Rights Reserved.

#include "Ui/AchieveI.h"
#include "System/Glass.h"

#include "System/UiManager.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"

AchieveIO::AchieveIO(GlassC* InGlass) : Io(InGlass)
{
	bActive = false;
}


void AchieveIO::Activate()
{
	GBIND("achieve_OnEnd", this, &AchieveIO::OnEnd);
}

void AchieveIO::Award(AchieveTemp* NewAward)
{
	AchieveQue.push_back(NewAward);
	if (bActive == false)
	{
		bActive = true;
		GSEND0("achieve_award");
		AchieveQue.erase(AchieveQue.begin());
	}
}

void AchieveIO::OnEnd()
{
	if (AchieveQue.size() > 0)
	{
		GSEND0("achieve_award");
		AchieveQue.erase(AchieveQue.begin());
	}
	else
	{
		bActive = false;
	}
}
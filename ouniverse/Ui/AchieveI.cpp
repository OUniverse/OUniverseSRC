//Copyright 2015-2019, All Rights Reserved.

#include "Ui/AchieveI.h"
#include "CohtmlHUD.h"

#include "System/UiManager.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"

AchieveIO::AchieveIO(UCohtmlHUD* InUi) : Io(InUi)
{
	bActive = false;
}


void AchieveIO::Activate()
{
	Ui->GetView()->BindCall("achieve_OnEnd", cohtml::MakeHandler(this, &AchieveIO::OnEnd));
}

void AchieveIO::Award(AchieveTemp* NewAward)
{
	AchieveQue.push_back(NewAward);
	if (bActive == false)
	{
		bActive = true;
		Ui->GetView()->TriggerEvent("achieve_award");
		AchieveQue.erase(AchieveQue.begin());
	}
}

void AchieveIO::OnEnd()
{
	if (AchieveQue.size() > 0)
	{
		Ui->GetView()->TriggerEvent("achieve_award");
		AchieveQue.erase(AchieveQue.begin());
	}
	else
	{
		bActive = false;
	}
}
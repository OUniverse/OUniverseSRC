//Copyright 2015-2019, All Rights Reserved.

#include "Ui/I_Achieve.h"

#include "CohtmlHUD.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"

UI_Achieve::UI_Achieve()
{
	bActive = false;
}


void UI_Achieve::Activate()
{
	Ui->GetView()->BindCall("achieve_OnEnd", cohtml::MakeHandler(this, &UI_Achieve::OnEnd));
}

void UI_Achieve::Award(UAchieveTemp* NewAward)
{
	AchieveQue.Add(NewAward);
	if (bActive == false)
	{
		bActive = true;
		Ui->GetView()->TriggerEvent("achieve_award");
		AchieveQue.RemoveAt(0, 1, true);
	}
}

void UI_Achieve::OnEnd()
{
	if (AchieveQue.Num() > 0)
	{

		Ui->GetView()->TriggerEvent("achieve_award");
		AchieveQue.RemoveAt(0, 1, true);
	}
	else
	{
		bActive = false;
	}
}
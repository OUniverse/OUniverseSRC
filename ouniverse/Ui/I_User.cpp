//Copyright 2015-2019, All Rights Reserved.

#include "Ui/I_User.h"
#include "System/Major.h"
#include "System/UserManager.h"
#include "System/User.h"
#include "System/ConfigManager.h"
#include "System/LogMinimal.h"


#include "CohtmlHUD.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"

UI_User::UI_User()
{
	bOpen = false;
}

void UI_User::Activate()
{
	Ui->GetView()->BindCall("user_onSelected", cohtml::MakeHandler(this, &UI_User::OnUserSelected));
}

void UI_User::King()
{

	if (!Major->UserManager->bActiveUserFound())
	{
		if (Major->UserManager->UserCount < 1)
		{
			LOG(LBOOT, 1, "IO-User: No Users found in directory. Prompting to create new user.");
			SetMode(EI_UserMode::Intro);
			return;
		}
		
		if (Major->UserManager->bSingleUserFound() && Major->ConfigManager->GetAsBool(EIniTypes::Global,OINI_AUTOLOG_SINGLE_USER))
		{
			//If there is only 1 user and bAutologSingleUser == true in global ini.
			LOG(LBOOT, 1, "IO-User: Bypassing UserSelect because "+FString(OINI_AUTOLOG_SINGLE_USER)+" is true and a user is found.");

			return;
		}
		
		if (Major->UserManager->bLastSessionUserFound() && Major->ConfigManager->GetAsBool(EIniTypes::Global, OINI_AUTOLOG_LAST_USER))
		{
			//If bAutoLogLastUser == true in global ini and that User ID is currently findable by the UserManager.
			LOG(LBOOT, 1, "IO-User: Bypassing UserSelect because " + FString(OINI_AUTOLOG_LAST_USER) + " is true and a user is found.");
			return;
		}
		
		LOG(LBOOT, 1, "IO-User: No bypass flags activated and one or more users have been found.");
		SetMode(EI_UserMode::Select);
		return;
	}

	LOG(LBOOT, 1, "IO-User: A User has already been selected proceeding straight to the select menu.");
	SetMode(EI_UserMode::Select);
	return;
}


void UI_User::SetMode(EI_UserMode NewMode)
{
	Ui->GetView()->TriggerEvent("user_sendUserData");
	Ui->GetView()->TriggerEvent("user_modeSelect");
}


void UI_User::OnUserSelected()
{

}
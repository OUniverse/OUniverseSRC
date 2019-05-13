//Copyright 2015-2019, All Rights Reserved.

#include "Ui/SystemMenu/UserISM.h"

#include "System/Major.h"
#include "System/UserLib.h"
#include "System/UiManager.h"
#include "System/User.h"
#include "System/ConfigManager.h"

#include "Ui/SystemMenuI.h"

#include "CohtmlHUD.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"
#include "CohtmlTArrayBinder.h"
#include "CohtmlUTypeBinder.h"

UserISM::UserISM(UCohtmlHUD* InUi, SystemMenuIO* InSymu, UserLib* InUser, ConfigManager* InConfig) : IoSM(InUi, InSymu)
{
	UserP = InUser;
	ConfigP = InConfig;
	bOpen = false;
	bSentUsers = false;
}

void UserISM::Activate()
{
	Ui->GetView()->BindCall("sysmenu.user.onSelected", cohtml::MakeHandler(this, &UserISM::OnUserSelected));
	Ui->GetView()->BindCall("sysmenu.user.onDeleted", cohtml::MakeHandler(this, &UserISM::OnUserDeleted));
	Ui->GetView()->BindCall("sysmenu.user.onEdited", cohtml::MakeHandler(this, &UserISM::OnUserEdited));
	Ui->GetView()->BindCall("sysmenu.user.onAdded", cohtml::MakeHandler(this, &UserISM::OnUserAdded));
}

void UserISM::King()
{

	if (!UserP->bActiveUserFound())
	{
		if (UserP->Num() < 1)
		{
			//LOG(LBOOT, 1, "IO-User: No Users found in directory. Prompting to create new user.");
			Open(Modes::Create);
			return;
		}
		
		if (UserP->bSingleUserFound() && ConfigP->GetBool(ConfigManager::IniTypes::Global,IniKey::Global::Bool::LoginSingleUser))
		{
			//If there is only 1 user and bAutologSingleUser == true in global ini.
			//LOG(LBOOT, 1, "IO-User: Bypassing UserSelect: "+FString(OINI_AUTOLOG_SINGLE_USER)+" is true and single user is found.");
			SystemMenuP->OnSubMenuConcluded();
			return;
		}
		
		if (UserP->bLastSessionUserFound() && ConfigP->GetBool(ConfigManager::IniTypes::Global, IniKey::Global::Bool::LoginLastUser))
		{
			//If bAutoLogLastUser == true in global ini and that User ID is currently findable by the UserManager.
			//LOG(LBOOT, 1, "IO-User: Bypassing UserSelect: " + FString(OINI_AUTOLOG_LAST_USER) + " is true and a user is found.");			
			SystemMenuP->OnSubMenuConcluded();
			return;
		}
		
		//LOG(LBOOT, 1, "IO-User: No bypass flags activated and one or more users have been found.");
		Open(Modes::Select);
		return;
	}

	//LOG(LBOOT, 1, "IO-User: A User has already been selected proceeding straight to the select menu.");
	Open(Modes::Select);
	return;
}

void UserISM::Open(Modes NewMode)
{
	Mode = NewMode;
	FString ModeString;

	if (NewMode == Modes::Select)
	{
		ModeString = "select";
		//for (int i = 0; i < Major->UserManager->UserCount; i++)
		//{
			if (!bSentUsers)
			{
			bSentUsers = true;
			//User isn't a UE4 type so this was causing some propblems during refactoring, implement it in a bit
			//Ui->GetView()->TriggerEvent("sysmenu.user.addUsers", UserP->Users);
			}
		//}
	}
	else 
	{
		ModeString = "create";
	}
	SystemMenuP->OpenSubMenu("user", ModeString);
}


void UserISM::OnActiveUserChanged()
{

}

void UserISM::OnUserSelected(int UserSN)
{
	UserP->SetUserBySN(UserSN);	
	SystemMenuP->OnSubMenuConcluded();
}

void UserISM::OnUserAdded()
{

}

void UserISM::OnUserEdited()
{

}

void UserISM::OnUserDeleted()
{

}
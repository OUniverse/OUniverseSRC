//Copyright 2015-2019, All Rights Reserved.

#include "Ui/SystemMenu/UserISM.h"

#include "System/Major.h"
#include "System/UserLib.h"
#include "System/UiManager.h"
#include "System/User.h"
#include "System/ConfigManager.h"

#include "Ui/SystemMenuI.h"

#include "System/Glass.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"
#include "CohtmlTArrayBinder.h"
#include "CohtmlUTypeBinder.h"

UserISM::UserISM(GlassC* InGlass, SystemMenuIO* InSymu, UserLibC* InUser, ConfigManager* InConfig) : IoSM(InGlass, InSymu)
{
	UserP = InUser;
	ConfigP = InConfig;
	bOpen = false;
	bSentUsers = false;
}

void UserISM::Activate()
{
	GBIND("sysmenu.user.onSelected", this, &UserISM::OnUserSelected);
	GBIND("sysmenu.user.onDeleted", this, &UserISM::OnUserDeleted);
	GBIND("sysmenu.user.onEdited", this, &UserISM::OnUserEdited);
	GBIND("sysmenu.user.onAdded", this, &UserISM::OnUserAdded);
}

void UserISM::King()
{

	if (!UserP->IsUserChosen())
	{
		
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
	//UserP->SetUserBySN(UserSN);	
	//SystemMenuP->OnSubMenuConcluded();
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
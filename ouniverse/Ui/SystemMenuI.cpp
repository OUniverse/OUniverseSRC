//Copyright 2015-2019, All Rights Reserved.

#include "Ui/SystemMenuI.h"
#include "Ui/Io.h"
#include "System/Glass.h"


#include "System/UserLib.h"
#include "System/Paths.h"

#include "Ui/SystemMenu/CreationISM.h"
#include "Ui/SystemMenu/CreditsISM.h"
#include "Ui/SystemMenu/DataISM.h"
#include "Ui/SystemMenu/DetailsISM.h"
#include "Ui/SystemMenu/PlaythroughISM.h"
#include "Ui/SystemMenu/NewsISM.h"
#include "Ui/SystemMenu/SettingsISM.h"
#include "Ui/SystemMenu/TitleISM.h"
#include "Ui/SystemMenu/UserISM.h"

#include "Util/FileFriend.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"
#include "CohtmlUTypeBinder.h"
#include "CohtmlTArrayBinder.h"

#include "Min/MajorM.h"

SystemMenuIO::SystemMenuIO(GlassC* InGlass) : Io(InGlass)
{

	MAJOR_IN_USAGE//In Activate()

	bOverlayEnabled = false;
	SubMenuVector.assign(SubMenus::MAX, NULL);

	SubMenuStringMap.insert({ "creation", SubMenus::Creation } );
	SubMenuStringMap.insert({ "credits", SubMenus::Credits } );
	SubMenuStringMap.insert({ "data", SubMenus::Data } );
	SubMenuStringMap.insert({ "details", SubMenus::Details } );
	SubMenuStringMap.insert({ "instance", SubMenus::Playthrough } );
	SubMenuStringMap.insert({ "news", SubMenus::News } );
	SubMenuStringMap.insert({ "settings", SubMenus::Settings } );
	SubMenuStringMap.insert({ "title", SubMenus::Title } );
	SubMenuStringMap.insert({ "user", SubMenus::User } );
}

void SystemMenuIO::Activate()
{



	GBIND("sysmenu.onMenuClose", this, &SystemMenuIO::OnMenuClose);

	
	
	CreationISM* IsmCreation = new CreationISM(Glass_,this);
	SubMenuVector[SubMenus::Creation] = IsmCreation;

	UserISM* IsmUser = new UserISM(Glass_, this, MAJOR->User(), MAJOR->Config());
	SubMenuVector[SubMenus::User] = IsmUser;
	IsmUser->Activate();
	
	TitleISM* IsmTitle = new TitleISM(Glass_, this);
	SubMenuVector[SubMenus::Title] = IsmTitle;
	IsmTitle->Activate();

}

void SystemMenuIO::King()
{
	GSEND0("sysmenu.open");
	EvaluateOptions();

	if (!MajorC::Get()->User()->IsUserChosen())
	{
		SetOverlayEnabled(false);
		GetMenu(SubMenus::User)->King();
		return;
	}

	
	GetMenu(SubMenus::Title)->King();
}


SystemMenuIO::SubMenus SystemMenuIO::GetMenuEnumFromString(FString ModeAsString)
{
	return SubMenuStringMap.at(ModeAsString);
}

IoSM* SystemMenuIO::GetMenu(SubMenus Menu)
{
	return SubMenuVector[Menu];
}

void SystemMenuIO::SetMenu(SubMenus NewMode)
{
	if (ActiveMenu!=NULL)
	{
		Io* LastMenu = ActiveMenu;
		ActiveMenu = GetMenu(NewMode);
		GSEND0("sysmenu.closeActiveSubMenu");
	}
	else {
		ActiveMenu = GetMenu(NewMode);
		OnMenuClose("none");
	}
}

void SystemMenuIO::OnMenuClose(FString MenuID)
{
	ActiveMenu->King();
}

void SystemMenuIO::OnSubMenuConcluded()
{
	SetOverlayEnabled(true);
	SetMenu(SubMenus::Title);
}

void SystemMenuIO::EvaluateOptions()
{
	GSEND1("sysmenu.updateOptions", Options);
}

void SystemMenuIO::SetOverlayEnabled(bool bEnable)
{
	bOverlayEnabled = bEnable;
}

void SystemMenuIO::OpenSubMenu(FString MenuID, FString OpenMode)
{
	GSEND2("sysmenu.openSubMenu", MenuID, OpenMode);
}
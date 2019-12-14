//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymMain.h"
#include "Protocol/System/SymPro.h"

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

#include "Ui/System/SYM_Home.h"
#include "Ui/System/SymSettings.h"
#include "Ui/System/SymNews.h"

void USYM_Main::Init(UUiView* InParentView, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib)
{
	ConstructView(InParentView);

	UserLib_ = InUserLib;
	LoadoutLib_ = InLoadoutLib;

	AddViewPanel(0);

	BT_Glory->SetupButton(Interfaces::BTGlory, this);
	BT_Settings->SetupButton(Interfaces::BTSettings, this);
	BT_News->SetupButton(Interfaces::BTNews, this);
	BT_Journey->SetupButton(Interfaces::BTJourney, this);
	BT_Continue->SetupButton(Interfaces::BTContinue, this);
	BT_Scribe->SetupButton(Interfaces::BTScribe, this);

	View_Home->Init(this);
	AddView(0, Views::Home, View_Home);
	View_Settings->Init(this);
	AddView(0, Views::Settings, View_Settings);
	View_News->Init(this);
	AddView(0, Views::News, View_News);

}


void USYM_Main::EventUi(int InWidgetID, int InEventID, UUserWidget* InWidget)
{
	switch (InEventID) {
	case UiEventCodesC::ButtonClick:
		switch (InWidgetID) {
		case Interfaces::BTHome:
			SwitchView(0, Views::Home);
			break;
		case Interfaces::BTSettings:
			SwitchView(0, Views::Settings);
			break;
		case Interfaces::BTNews:
			SwitchView(0, Views::News);
			break;
		case Interfaces::BTScribe:
			//(static_cast<SymC*>(Shell()))->Protocol()->GoToWriter();
			break;
		}
		break;
	}
}
//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymMenuU.h"
#include "Protocol/System/SymMenuP.h"

#include "Ui/UiButtonNew.h"
#include "Ui/UiEventCodes.h"

void USymMenu::NativeConstruct()
{
	Super::NativeConstruct();

	V_NewGame->SetupButton(REG::NewGame, this);
	V_Continue->SetupButton(REG::Continue, this);
	V_User->SetupButton(REG::User, this);
	V_Loadout->SetupButton(REG::Loadout, this);
	V_Trophey->SetupButton(REG::Trophey, this);
	V_Settings->SetupButton(REG::Settings, this);
	V_Update->SetupButton(REG::Update, this);

	V_Credits->SetupButton(REG::Credits, this);
	V_News->SetupButton(REG::News, this);
	V_Scribe->SetupButton(REG::Scribe, this);
}

void USymMenu::UiConstruct(SymMenuP* InPro)
{
	Pro_ = InPro;
}

void USymMenu::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	if (InEventID == UiEventsC::ButtonAccept)
	{
		switch (WidgetID) {
		case REG::User:
			Pro_->AcceptUser();
			break;
		case REG::Scribe:
			Pro_->AcceptWriter();
			break;
		}

	}
}
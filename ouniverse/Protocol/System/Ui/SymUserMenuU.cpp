//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymUserMenuU.h"
#include "Protocol/System/SymUserMenuP.h"

#include "Ui/UiEventCodes.h"
#include "Ui/UiButtonNew.h"

#include "Min/DebugM.h"

void USymUserMenu::NativeConstruct()
{
	Super::NativeConstruct();

	V_Create->SetupButton(REG::New,this);
	V_Select->SetupButton(REG::Select,this);
	V_Edit->SetupButton(REG::Edit,this);
	V_Back->SetupButton(REG::Back,this);
}

void USymUserMenu::UiConstruct(SymUserMenuP* InPro)
{
	Pro_ = InPro;
}

void USymUserMenu::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{

	
	if (InEventID == UiEventsC::ButtonAccept)
	{
		switch (WidgetID) {
		case REG::New:
			Pro_->AcceptCreate();
			break;
		case REG::Select:
			Pro_->AcceptSelect();
			break;
		case REG::Edit:
			Pro_->AcceptEdit();
			break;
		case REG::Back:
			Pro_->AcceptBack();
			break;
		}
	}
}
//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriMainU.h"
#include "Protocol/Writer/WriMainP.h"

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

void UWriMenu::NativeConstruct()
{
	Super::NativeConstruct();

	BT_Loadout->SetupButton(REG::Loadout, this);
	BT_Atlas->SetupButton(REG::Atlas, this);
	BT_Form->SetupButton(REG::Form, this);


}

void UWriMenu::UiConstruct(WriMenuP* InPro)
{
	Pro_ = InPro;
}

void UWriMenu::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	if (InEventID == UiEventsC::ButtonAccept || InEventID == UiEventsC::MouseLeftClick)
	{
		switch (WidgetID) {
		case REG::Loadout:
			Pro_->AcceptLoadout();
			break;
		case REG::Atlas:
			Pro_->AcceptAtlas();
			break;
		case REG::Form:
			Pro_->AcceptForm();
			break;
		}

	}
}
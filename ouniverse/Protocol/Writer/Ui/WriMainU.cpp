//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriMainU.h"
#include "Protocol/Writer/WriMainP.h"

#include "Protocol/Writer/Ui/WriButtonU.h"
#include "Ui/UiEventCodes.h"

void UWriMenu::NativeConstruct()
{
	Super::NativeConstruct();

	vLoadout->SetupButton(REG::RLoadout, this);
	vLoadout->SetTextHash(86665931);

	vAtlas->SetupButton(REG::RAtlas, this);
	vAtlas->SetTextHash(1539337606);

	vData->SetupButton(REG::RData, this);
	vData->SetTextHash(1872351585);

	vWorld->SetupButton(REG::RWorld, this);
	vWorld->SetTextHash(1234621014);

	vTools->SetupButton(REG::RTools, this);
	vTools->SetTextHash(867510666);

	vExit->SetupButton(REG::RExit, this);
	vExit->SetTextHash(28132344);


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
		case REG::RLoadout:
			Pro_->AcceptLoadout();
			break;
		case REG::RAtlas:
			Pro_->AcceptAtlas();
			break;
		case REG::RData:
			Pro_->AcceptForm();
			break;
		}

	}
}
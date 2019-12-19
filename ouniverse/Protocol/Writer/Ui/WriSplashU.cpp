//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriSplashU.h"
#include "Protocol/Writer/WriSplashP.h"

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

void UWriSplash::NativeConstruct()
{
	Super::NativeConstruct();

	V_Start->SetupButton(REG::Start, this);
	V_Back->SetupButton(REG::Back, this);

}

void UWriSplash::UiConstruct(WriSplashP* InPro)
{
	Pro_ = InPro;
}

void UWriSplash::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	if (InEventID == UiEventsC::ButtonAccept)
	{
		switch (WidgetID) {
		case REG::Start:
			Pro_->AcceptStart();
			break;
		case REG::Back:
			Pro_->AcceptBack();
			break;
		}

	}
}
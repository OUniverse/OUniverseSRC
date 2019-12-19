//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymLoadoutMenuU.h"
#include "Protocol/System/SymLoadoutMenuP.h"

#include "Ui/UiEventCodes.h"
#include "Ui/UiButton.h"

#include "Min/DebugM.h"

void USymLoadoutMenu::NativeConstruct()
{
	Super::NativeConstruct();

}

void USymLoadoutMenu::UiConstruct(SymLoadoutMenuP* InPro)
{
	Pro_ = InPro;
}

void USymLoadoutMenu::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
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
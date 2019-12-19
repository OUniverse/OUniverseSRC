//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFormU_Port.h"
#include "Protocol/Writer/Ui/WriFormU_PortRack.h"
#include "Protocol/Writer/Ui/WriButtonU.h"

#include "Components/TextBlock.h"

#include "Ui/UiEventCodes.h"
#include "System/FormData.h"
#include "Form/FormF.h"

void UWriForm_Port::NativeConstruct()
{
	Super::NativeConstruct();
	vClose->SetupButton(REG::RClose, this);

}

void UWriForm_Port::Init(UWriForm_PortRack* InPortRack)
{
	PortRack_ = InPortRack;
}

void UWriForm_Port::Assign(FormDataC* InForm)
{
	Form_ = InForm;
	vId->SetText(Form_->Form()->ID().ToFText());
}

void UWriForm_Port::Clear()
{
	vId->SetText(StringC("").ToFText());
}

void UWriForm_Port::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	switch (WidgetID) {
	case REG::RClose:

		if (InEventID == UiEventsC::Code::MouseLeftClick)
		{
			PortRack_->PortClose(this);
		}
		break;
	}
}

void UWriForm_Port::TechOpen(FormDataC* InForm)
{
	Form_ = InForm;
	vId->SetText(Form_->Form()->ID().ToFText());
}

void UWriForm_Port::TechClose()
{
	vId->SetText(StringC("").ToFText());
}
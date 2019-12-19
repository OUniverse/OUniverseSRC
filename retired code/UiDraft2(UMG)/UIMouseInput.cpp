//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiMouseInput.h"
#include "Ui/UiBase.h"
#include "Ui/UiEventCodes.h"
#include "Ui/UiStatics.h"

void UUiMouseInput::NativeConstruct()
{
	bIsFocusable = true;
	Super::NativeConstruct();
}


FReply UUiMouseInput::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bPressed = true;
	return Relay_->EventMouseButtonDown(ID_,MyGeometry,MouseEvent);
	return FReply::Handled();
}

FReply UUiMouseInput::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	FReply MyReply = Relay_->EventMouseButtonUp(ID_, MyGeometry, MouseEvent);

	if (bPressed == true)
	{		
		MyReply = Relay_->EventMouseClick(ID_, MyGeometry, MouseEvent);
	}

	bPressed = false;
	return MyReply;
}

FReply UUiMouseInput::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return Relay_->EventMouseMove(ID_, MyGeometry, MouseEvent);
}

void UUiMouseInput::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	//UUi_Statics::FocusWidget(this);

	Relay_->EventMouseEnter(ID_, MyGeometry, MouseEvent);
}

void UUiMouseInput::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	Relay_->EventMouseLeave(ID_, MouseEvent);
}
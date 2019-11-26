//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UI_MouseInput.h"
#include "Ui/Ui_Base.h"
#include "Ui/Ui_EventCodes.h"

FReply UUI_MouseInput::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bPressed = true;
	return Relay_->EventMouseButtonDown(ID_,MyGeometry,MouseEvent);
	return FReply::Handled();
}

FReply UUI_MouseInput::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	FReply MyReply = Relay_->EventMouseButtonUp(ID_, MyGeometry, MouseEvent);

	if (bPressed == true)
	{		
		MyReply = Relay_->EventMouseClick(ID_, MyGeometry, MouseEvent);
	}

	bPressed = true;
	return MyReply;
}

FReply UUI_MouseInput::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return Relay_->EventMouseMove(ID_, MyGeometry, MouseEvent);
}

void UUI_MouseInput::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	Relay_->EventMouseEnter(ID_, MyGeometry, MouseEvent);
}

void UUI_MouseInput::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	Relay_->EventMouseLeave(ID_, MouseEvent);
}
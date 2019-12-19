//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiButton.h"
#include "Ui/UiView.h"

#include "Ui/UiEventCodes.h"


void UUiButton::SetupButton(int InID, UUiBase* InRelay)
{
	bIsFocusable = true;
	ID_ = InID;
	Relay_ = InRelay;
}

bool UUiButton::Select_Internal()
{
	Select();
	SelectBP();
	return false;
}


void UUiButton::Select()
{

}

bool UUiButton::Deselect_Internal()
{
	Deselect();
	DeselectBP();

	return false;
}

void UUiButton::Deselect()
{

}


FReply UUiButton::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bPressed = true;
	Relay_->EventUi(ID_, UiEventCodesC::ButtonMouseDown, this);
	return FReply::Handled();
}

FReply UUiButton::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{

	Relay_->EventUi(ID_, UiEventCodesC::ButtonMouseUp, this);

	if (bPressed)
	{
		Relay_->EventUi(ID_, UiEventCodesC::ButtonClick, this);
	}

	bPressed = false;
	return FReply::Handled();
}

void UUiButton::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	Relay_->EventUi(ID_,UiEventCodesC::ButtonHover,this);
	HoveredBP();
}

void UUiButton::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	Relay_->EventUi(ID_, UiEventCodesC::ButtonUnhover, this);
	UnhoveredBP();
}
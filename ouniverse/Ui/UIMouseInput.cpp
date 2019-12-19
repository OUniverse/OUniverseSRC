//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiMouseInput.h"
#include "Ui/UiEventCodes.h"
#include "Ui/UiBase.h"

void UUiMouseInput::NativeConstruct()
{
	bIsFocusable = true;
	bHitDisabled = false;
	bEventDisabled = false;
	Super::NativeConstruct();
}

void UUiMouseInput::Setup(int InID, UUiBase* InRelay)
{
	ID_ = InID;
	Relay_ = InRelay;
}

FReply UUiMouseInput::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bPressed = true;
	MouseEvent.GetEffectingButton();
	Relay_->EventUi(ID_,0,this);
	return FReply::Handled();
}

FReply UUiMouseInput::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

FReply UUiMouseInput::NativeOnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bPressed = true;
	MouseEvent.GetEffectingButton();
	Relay_->EventUi(ID_, 0, this);
	return FReply::Handled();
}

FReply UUiMouseInput::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

void UUiMouseInput::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	//UUi_Statics::FocusWidget(this);

	//Relay_->EventMouseEnter(ID_, MyGeometry, MouseEvent);
}

void UUiMouseInput::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	//Relay_->EventMouseLeave(ID_, MouseEvent);
}
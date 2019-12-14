//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiMouseRelay.h"
#include "Ui/UiEventCodes.h"
#include "Ui/UiBaseNew.h"

void UUiMouseRelay::NativeConstruct()
{
	bIsFocusable = true;
	bHitDisabled = false;
	bEventDisabled = false;
	Super::NativeConstruct();
}

void UUiMouseRelay::Setup(int InID, UUiBaseNew* InRelay)
{
	ID_ = InID;
	Relay_ = InRelay;
}

FReply UUiMouseRelay::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bPressed = true;
	MouseEvent.GetEffectingButton();
	Relay_->EventUi(0,0,this);
		
	return FReply::Handled();
}

FReply UUiMouseRelay::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

FReply UUiMouseRelay::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

void UUiMouseRelay::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	//UUi_Statics::FocusWidget(this);

	//Relay_->EventMouseEnter(ID_, MyGeometry, MouseEvent);
}

void UUiMouseRelay::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	//Relay_->EventMouseLeave(ID_, MouseEvent);
}
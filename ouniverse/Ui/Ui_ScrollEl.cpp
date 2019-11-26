//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_ScrollEl.h"
#include "Components/SizeBox.h"

#include "Min/DebugM.h"


void UUi_ScrollEl::SetParentScroll(UUi_Scroll* InScroll)
{
	OwningScroll_ = InScroll;
}

void UUi_ScrollEl::Hovered_Mechanism()
{
	HoveredBP();
}

void UUi_ScrollEl::Unhovered_Mechanism()
{
	UnhoveredBP();
}

void UUi_ScrollEl::Centered_Mechanism()
{
	CenteredBP();
}

void UUi_ScrollEl::Uncentered_Mechanism()
{
	UncenteredBP();
}

FReply UUi_ScrollEl::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	PreciseClickTracker = 0.0f;

	return FReply::Unhandled();
}

FReply UUi_ScrollEl::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{

	if (PreciseClickTracker < 0.1)
	{
		PreciseClick(MyGeometry,MouseEvent);
	}

	return FReply::Unhandled();
}

FReply UUi_ScrollEl::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (PreciseClickTracker < 0.1)
	{
		//UnHover
	}

	PreciseClickTracker += MouseEvent.GetCursorDelta().Size();
	return FReply::Unhandled();
}

void UUi_ScrollEl::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bHovered = true;
	Hovered_Mechanism();
}

void UUi_ScrollEl::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	bHovered = false;
	Unhovered_Mechanism();
}
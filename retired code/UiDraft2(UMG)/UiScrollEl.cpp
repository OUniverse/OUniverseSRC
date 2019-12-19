//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiScrollEl.h"
#include "Components/SizeBox.h"

#include "Min/DebugM.h"



void UUiScrollEl::SetParentScroll(UUiScroll* InScroll)
{
	OwningScroll_ = InScroll;
}

void UUiScrollEl::Hovered_Mechanism()
{
	HoveredBP();
}

void UUiScrollEl::Unhovered_Mechanism()
{
	UnhoveredBP();
}

void UUiScrollEl::Centered_Mechanism()
{
	CenteredBP();
}

void UUiScrollEl::Uncentered_Mechanism()
{
	UncenteredBP();
}

FReply UUiScrollEl::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	PreciseClickTracker = 0.0f;

	return FReply::Unhandled();
}

FReply UUiScrollEl::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{

	if (PreciseClickTracker < 0.1)
	{
		PreciseClick(MyGeometry,MouseEvent);
	}

	return FReply::Unhandled();
}

FReply UUiScrollEl::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (PreciseClickTracker < 0.1)
	{
		//UnHover
	}

	PreciseClickTracker += MouseEvent.GetCursorDelta().Size();
	return FReply::Unhandled();
}

void UUiScrollEl::NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bHovered = true;
	Hovered_Mechanism();
}

void UUiScrollEl::NativeOnMouseLeave(const FPointerEvent& MouseEvent)
{
	bHovered = false;
	Unhovered_Mechanism();
}
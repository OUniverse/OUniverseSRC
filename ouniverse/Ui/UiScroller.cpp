//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiScroller.h"
#include "Ui/UiScrollerEntry.h"
#include "Components/VerticalBox.h"

void UUiScroller::AddEntry(UUiScrollerEntry* InEntry)
{
	V_Case->AddChild(InEntry);
	InEntry->SetParentScroll(this);
	Entries_.Add(InEntry);
}

void UUiScroller::ClearChildren()
{
	//V_Scroll->ClearChildren();
}

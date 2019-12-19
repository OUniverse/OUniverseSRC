//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiScroll.h"
#include "Ui/UiScrollEntry.h"
#include "Components/VerticalBox.h"

void UUiScroll::AddEntry(UUiScrollEntry* InEntry)
{
	V_Case->AddChild(InEntry);
	InEntry->SetParentScroll(this);
	Entries_.Add(InEntry);
}

void UUiScroll::ClearChildren()
{
	//V_Scroll->ClearChildren();
}

//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_ScrollBox.h"
#include "Components/ScrollBox.h"



void UUi_ScrollBox::Add(UUserWidget* InChild)
{
	V_Scroll->AddChild(InChild);
}
void UUi_ScrollBox::ClearChildren()
{
	V_Scroll->ClearChildren();
}
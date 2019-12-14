//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_ScrollodexEl.h"
#include "Components/SizeBox.h"

void UUi_ScrollodexEl::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUi_ScrollodexEl::Require(USizeBox* InSizeBox)
{
	V_Size = InSizeBox;
}

void UUi_ScrollodexEl::SetHeight(float InHeight)
{
	V_Size->SetHeightOverride(InHeight);
}
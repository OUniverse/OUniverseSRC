//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_RolodexEl.h"
#include "Components/SizeBox.h"

void UUi_RolodexEl::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUi_RolodexEl::Require(USizeBox* InSizeBox)
{
	V_Size = InSizeBox;
}

void UUi_RolodexEl::SetHeight(float InHeight)
{
	V_Size->SetHeightOverride(InHeight);
}
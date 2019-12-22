//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Json/UiJsonType.h"
#include "Ui/UiButton.h"

void UUiJsonType::NativeConstruct()
{
	Super::NativeConstruct();
	vDelete->SetupButton(Reg::RDelete, this);
}

void UUiJsonType::SetShell(UUiJson* InShell)
{
	Shell_ = InShell;
}

void UUiJsonType::NativeDestruct()
{
	Super::NativeDestruct();
}

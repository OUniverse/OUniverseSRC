//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFormU.h"
#include "Protocol/Writer/WriFormP.h"

#include "Ui/UiButtonNew.h"
#include "Ui/UiEventCodes.h"

void UWriForm::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWriForm::UiConstruct(WriFormP* InPro)
{
	Pro_ = InPro;
}
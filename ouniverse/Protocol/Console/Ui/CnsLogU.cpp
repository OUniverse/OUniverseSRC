//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/Ui/CnsLogU.h"
#include "Protocol/Console/CnsLogP.h"

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

void UCnsLog::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCnsLog::UiConstruct(CnsLogP* InPro)
{
	Pro_ = InPro;
}
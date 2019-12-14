//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/Ui/CnsOutputU.h"
#include "Protocol/Console/CnsOutputP.h"

#include "Ui/UiButtonNew.h"
#include "Ui/UiEventCodes.h"

void UCnsOutput::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCnsOutput::UiConstruct(CnsOutputP* InPro)
{
	Pro_ = InPro;
}
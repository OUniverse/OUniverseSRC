//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/Ui/CnsShelfU.h"
#include "Protocol/Console/CnsShelfP.h"

#include "Ui/UiButtonNew.h"
#include "Ui/UiEventCodes.h"


void UCnsShelf::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCnsShelf::UiConstruct(CnsShelfP* InPro)
{
	Pro_ = InPro;
}
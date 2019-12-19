//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Console/Ui/CnsTrayU.h"
#include "Protocol/Console/CnsTrayP.h"

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"

void UCnsTray::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCnsTray::UiConstruct(CnsTrayP* InPro)
{
	Pro_ = InPro;
}
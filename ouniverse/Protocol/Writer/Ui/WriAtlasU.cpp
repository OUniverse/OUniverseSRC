//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriAtlasU.h"
#include "Protocol/Writer/WriAtlasP.h"

#include "Ui/UiButtonNew.h"
#include "Ui/UiEventCodes.h"

void UWriAtlas::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWriAtlas::UiConstruct(WriAtlasP* InPro)
{
	Pro_ = InPro;
}
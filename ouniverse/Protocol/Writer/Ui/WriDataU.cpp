//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriDataU.h"
#include "Protocol/Writer/WriDataP.h"
#include "Protocol/Writer/WriPro.h"

#include "Protocol/Writer/Ui/WriFormEditU.h"

#include "Components/TextBlock.h"
#include "Protocol/Writer/Ui/WriButtonU.h"
#include "Ui/UiEventCodes.h"

void UWriData::NativeConstruct()
{
	Super::NativeConstruct();

	vDscView->SetText(WriterPro::Dict(1914866211));

	vSearch0->SetupButton(REG::RSearch0, this);
	vSearch1->SetupButton(REG::RSearch1, this);
	vSearch2->SetupButton(REG::RSearch2, this);
}

void UWriData::NativeDestruct()
{
	Super::NativeDestruct();
}

void UWriData::UiConstruct(WriDataP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}
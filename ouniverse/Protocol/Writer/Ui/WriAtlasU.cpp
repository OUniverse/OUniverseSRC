//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriAtlasU.h"
#include "Protocol/Writer/WriAtlasP.h"

#include "Ui/UiButton.h"
#include "Ui/UiEventCodes.h"
#include "Ui/FieldWriter/UiFieldWriterString.h"

#include "System/Atlas.h"


void UWriAtlas::NativeConstruct()
{
	Super::NativeConstruct();
	V_ID->SetupField(0,this);
	V_Author->SetupField(0, this);

}

void UWriAtlas::UiConstruct(WriAtlasP* InPro)
{
	Pro_ = InPro;
}

void UWriAtlas::OpenUI(AtlasC* InAtlas)
{
	V_ID->SetText(InAtlas->ID().ToFText());
	V_Author->SetText(InAtlas->Author().ToFText());
}
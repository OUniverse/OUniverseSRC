//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriLoadoutU.h"
#include "Protocol/Writer/Ui/WriLoadoutU_ScrollEntry.h"
#include "Protocol/Writer/WriLoadoutP.h"

#include "System/AtlasLib.h"

#include "Ui/UiScroller.h"
#include "Ui/UiButtonNew.h"
#include "Ui/UiEventCodes.h"

#include "Min/DebugM.h"

void UWriLoadout::NativeConstruct()
{
	Super::NativeConstruct();
	BT_Load->SetupButton(REG::Load, this);
}

void UWriLoadout::UiConstruct(WriLoadoutP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}

void UWriLoadout::OpenUi()
{
	//V_Scroll->ClearChildren();
	//Entries_.Empty();

	DBUG("WENT HERE")
	int L = AtlasLib_->GetAtlasPreMap()->Len();

	for (int i = 0; i < L; i++)
	{
		UWriLoadout_ScrollEntry* Entry = UWriLoadout_ScrollEntry::Create(this, AtlasLib_->GetAtlasPreMap()->At(i));
		V_Scroll->AddEntry(Entry);
		//Entries_.Emplace(Entry);


	}
}
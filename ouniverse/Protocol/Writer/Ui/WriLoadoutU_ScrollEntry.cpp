//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriLoadoutU_ScrollEntry.h"
#include "System/Scope.h"
#include "Class/ClassProtocol.h"

#include "System/Atlas.h"

#include "Components/TextBlock.h"

void UWriLoadout_ScrollEntry::NativeConstruct()
{
	Super::NativeConstruct();
	V_Text->SetText(FText::FromString(Atlas_->ID().ToChar()));
}

UWriLoadout_ScrollEntry* UWriLoadout_ScrollEntry::Create(UWriLoadout* InView, AtlasC* InAtlas)
{
	UWriLoadout_ScrollEntry* Neu = CreateWidget<UWriLoadout_ScrollEntry>(ScopeC::World(), UClassProtocol::Get()->WriLoadout_ScrollEntryUI);
	Neu->Init(InView, InAtlas);
	return Neu;
}

void UWriLoadout_ScrollEntry::Init(UWriLoadout* InView, AtlasC* InAtlas)
{
	Atlas_ = InAtlas;
}
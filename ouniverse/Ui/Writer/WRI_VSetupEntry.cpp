//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VSetupEntry.h"
#include "Ui/Writer/WRI_VSetup.h"

#include "System/AtlasLib.h"
#include "System/Atlas.h"

#include "Ui/Ui_Catch.h"

#include "Ui/Ui_Bool.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/ScrollBox.h"
#include "System/Class.h"


void UWRI_VSetupEntry::NativeConstruct()
{
	V_Catch->SetRelay(this);
	V_Text->SetText(FText::FromString(Atlas_->ID().ToChar()));
	V_Image->SetBrushFromTexture(Atlas_->GFXSmall());
	V_BoolMaster->SetRelay(View_);
	V_BoolSupport->SetRelay(View_);
	Super::NativeConstruct();
}

UWRI_VSetupEntry* UWRI_VSetupEntry::Create(UWorld* InScope, UWRI_VSetup* InView, AtlasC* InAtlas)
{
	UWRI_VSetupEntry* Neu = CreateWidget<UWRI_VSetupEntry>(InScope,ClassC::WRI_VSetupEntry());
	Neu->Init(InView, InAtlas);
	return Neu;
}

void UWRI_VSetupEntry::Init(UWRI_VSetup* InView, AtlasC* InAtlas)
{
	View_ = InView;
	Atlas_ = InAtlas;
}


FText UWRI_VSetupEntry::GetAtlasID()
{
	return FText();//FText::FromString(FString::FromInt(Atlas_->ID()));
}


UTexture2D* UWRI_VSetupEntry::GetAtlasIcon()
{
	return Atlas_->GFXSmall();
}


void UWRI_VSetupEntry::BoolChanged(EWRI_VSetupEntryBoolType Type)
{
	View_->BoolChanged(Type, this);
}
//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Loadout_Le.h"
#include "Ui/Writer/WRI_Loadout.h"

#include "System/Scope.h"
#include "System/AtlasLib.h"
#include "System/Atlas.h"

#include "Ui/Ui_Bool.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/ScrollBox.h"
#include "System/Class.h"


void UWRI_Loadout_Le::NativeConstruct()
{
	V_Text->SetText(FText::FromString(Atlas_->ID().ToChar()));
	V_Image->SetBrushFromTexture(Atlas_->GFXSmall());
	//V_BoolMaster->SetupInterface(this, Interfaces::Master);
	//V_BoolSupport->SetupInterface(this, Interfaces::Support);
	Super::NativeConstruct();
}

UWRI_Loadout_Le* UWRI_Loadout_Le::Create(UWRI_Loadout* InView, AtlasC* InAtlas)
{
	UWRI_Loadout_Le* Neu = CreateWidget<UWRI_Loadout_Le>(ScopeC::World(),ClassC::WRI_Loadout_Le());
	Neu->Init(InView, InAtlas);
	return Neu;
}

void UWRI_Loadout_Le::Init(UWRI_Loadout* InView, AtlasC* InAtlas)
{
	View_ = InView;
	Atlas_ = InAtlas;
}

/**
void UWRI_Loadout_Le::Click(UUi_Interactive* Interactive)
{
	View_->BoolChanged(Interactive->InterfaceUID(), this);
}
*/

bool UWRI_Loadout_Le::AtlasActivated()
{
	return V_BoolSupport->GetValue();
}
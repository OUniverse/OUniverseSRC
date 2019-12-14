//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_AtlasMount.h"
#include "System/Class.h"

#include "System/AtlasLib.h"

#include "UI/Title/TIM_Alpha.h"

#include "Min/DebugM.h"

void UTIM_AtlasMount::NativeConstruct()
{
	AtlasLib_->MountFromLoadout();
	Super::NativeConstruct();
}

UTIM_AtlasMount* UTIM_AtlasMount::Create(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	UTIM_AtlasMount* Neu = CreateWidget<UTIM_AtlasMount>(InParentView->Scope(), ClassC::TIM_AtlasMount());
	Neu->Init(InParentView, InAtlasLib);
	return Neu;
}

void UTIM_AtlasMount::Init(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	ConstructView(InParentView);

	AtlasLib_ = InAtlasLib;

	CastedAlpha = Cast<UTIM_Alpha>(Alpha());
}
//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_VMainVLoad.h"
#include "System/Class.h"

#include "System/AtlasLib.h"

#include "UI/Title/TIM_Alpha.h"


void UTIM_VMainVLoad::NativeConstruct()
{
	Super::NativeConstruct();
}

UTIM_VMainVLoad* UTIM_VMainVLoad::Create(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	UTIM_VMainVLoad* Neu = CreateWidget<UTIM_VMainVLoad>(InParentView->Scope(), ClassC::TIM_VMainVLoad());
	Neu->Init(InParentView, InAtlasLib);
	return Neu;
}

void UTIM_VMainVLoad::Init(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	StoreParentView(InParentView);

	AtlasLib_ = InAtlasLib;

	CastedAlpha = Cast<UTIM_Alpha>(Alpha());
}
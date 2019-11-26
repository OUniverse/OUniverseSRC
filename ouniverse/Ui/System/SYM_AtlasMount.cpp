//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_AtlasMount.h"
#include "System/Class.h"

#include "System/AtlasLib.h"

#include "UI/System/SYM_Alpha.h"

#include "Min/DebugM.h"

void USYM_AtlasMount::NativeConstruct()
{
	AtlasLib_->MountFromLoadout();
	Super::NativeConstruct();
}

USYM_AtlasMount* USYM_AtlasMount::Create(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	USYM_AtlasMount* Neu = CreateWidget<USYM_AtlasMount>(InParentView->Scope(), ClassC::SYM_AtlasMount());
	Neu->Init(InParentView, InAtlasLib);
	return Neu;
}

void USYM_AtlasMount::Init(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	StoreParentView(InParentView);

	AtlasLib_ = InAtlasLib;

	CastedAlpha = Cast<USYM_Alpha>(Alpha());
}
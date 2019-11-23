//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_AtlasMount.h"
#include "Ui/Writer/WRI_Alpha.h"
#include "Ui/Writer/WRI_Main.h"

#include "System/Class.h"

#include <thread>     

void UWRI_AtlasMount::MountThread(UWRI_Alpha* InAlpha)
{
	InAlpha->OpenLoadout();
}

void UWRI_AtlasMount::NativeConstruct()
{
	Super::NativeConstruct();
	
	UWRI_Alpha* CastedAlpha = Cast<UWRI_Alpha>(Alpha());
	MountingStart();
	std::thread first(MountThread, CastedAlpha);
	first.join();
	MountingComplete();
}

UWRI_AtlasMount* UWRI_AtlasMount::Create(UUi_View* InParentView)
{
	UWRI_AtlasMount* Neu = CreateWidget<UWRI_AtlasMount>(InParentView->Scope(), ClassC::WRI_AtlasMount());
	Neu->Init(InParentView);
	return Neu;
}

void UWRI_AtlasMount::Init(UUi_View* InParentView)
{
	StoreParentView(InParentView);
}

void UWRI_AtlasMount::AnimationComplete()
{
	OwningView_->SwitchView(0,UWRI_Main::VLoadout);
}
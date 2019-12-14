//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymAtlasLoad.h"
#include "Ui/System/SymReg.h"

#include "System/AtlasLib.h"
#include <thread> 



void USYM_AtlasLoad::Init(UUiView* InParentView, AtlasLibC* InAtlasLib)
{
	ConstructView(InParentView);
	AtlasLib_ = InAtlasLib;
}

void USYM_AtlasLoad::LoadingThread(AtlasLibC* InAtlasLib)
{
	InAtlasLib->MountFromLoadout();
}

void USYM_AtlasLoad::ViewOpen_Technical()
{
	std::thread first(LoadingThread, AtlasLib_);
	LoadStart();
	first.join();
	LoadComplete();
}

void USYM_AtlasLoad::AnimationComplete()
{
	OwningView_->SwitchView(SYMREG::Docks::DAlpha, SYMREG::Views::VMain);
}
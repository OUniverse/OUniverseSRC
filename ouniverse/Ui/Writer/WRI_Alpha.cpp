//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Alpha.h"

#include "Ui/Writer/WRI_Main.h"
#include "Ui/Writer/WRI_Splash.h"

#include "System/AtlasLib.h"
#include "System/Atlas.h"

#include "System/Class.h"




void UWRI_Alpha::NativeConstruct()
{
	MasterAtlas_ = NULL;
	SetViewPanel(0, V_View);

	SwitchView(0, UWRI_Alpha::VSplash);

	Super::NativeConstruct();
}


UWRI_Alpha* UWRI_Alpha::Create(UWorld* InScope, UUi* InUi, AtlasLibC* InAtlasLib)
{
	UWRI_Alpha* Neu = CreateWidget<UWRI_Alpha>(InScope, ClassC::WRI_Alpha());
	Neu->Init(InScope, InUi, InAtlasLib);
	return Neu;
}

void UWRI_Alpha::Init(UWorld* InScope, UUi* InUi, AtlasLibC* InAtlasLib)
{
	SetupAlpha(InScope, InUi);

	AtlasLib_ = InAtlasLib;
	AddViewPanel(0);
	View_Main = UWRI_Main::Create(this, InAtlasLib);
	AddView(0, UWRI_Alpha::VMain, View_Main);

	View_Splash = UWRI_Splash::Create(this);
	AddView(0, UWRI_Alpha::VSplash, View_Splash);

}


void UWRI_Alpha::OpenLoadout()
{
	AtlasLib_->MountFromWriter(&Loadout_);
}

void UWRI_Alpha::SetMasterAtlas(AtlasC* InMasterAtlas)
{
	if (MasterAtlas_ != NULL)
	{
		MasterAtlas_->WriterMasterUnload();
	}
	MasterAtlas_ = InMasterAtlas;
	MasterAtlas_->WriterMasterLoad();
}
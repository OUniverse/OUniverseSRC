//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/Wri.h"
#include "System/Scope.h"

#include "Ui/Writer/WRI_Main.h"
#include "Ui/Writer/WRI_Splash.h"

#include "System/AtlasLib.h"
#include "System/Atlas.h"

#include "System/Class.h"




void UWRI::NativeConstruct()
{
	MasterAtlas_ = NULL;
	//SetViewPanel(0, V_View);

	Super::NativeConstruct();

	AddViewPanel(0);

	View_Main->Init(this, AtlasLib_);
	AddView(0, UWRI::Views::Main, View_Main);


	SwitchView(0, UWRI::Views::Main);

	//SYM_Mem::FirstOpenComplete = true;
}


UWRI* UWRI::Create(WriterPro* InPro, AtlasLibC* InAtlasLib)
{
	UWRI* Neu = CreateWidget<UWRI>(ScopeC::World(), ClassC::WRI_Alpha());
	Neu->Init(InPro, InAtlasLib);
	return Neu;
}

void UWRI::Init(WriterPro* InPro, AtlasLibC* InAtlasLib)
{
	ConstructAlpha();
	Profile_ = InPro;
	AtlasLib_ = InAtlasLib;
}


void UWRI::OpenLoadout()
{
	AtlasLib_->MountFromWriter(&Loadout_);
}

void UWRI::SetMasterAtlas(AtlasC* InMasterAtlas)
{
	if (MasterAtlas_ != NULL)
	{
		MasterAtlas_->WriterMasterUnload();
	}
	MasterAtlas_ = InMasterAtlas;
	MasterAtlas_->WriterMasterLoad();
}
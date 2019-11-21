//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Alpha.h"
#include "Ui/Writer/WRI_AlphaOpt.h"

#include "Ui/Writer/WRI_VSetup.h"
#include "Ui/Writer/WRI_VForm.h"

#include "System/Babel.h"
#include "System/AtlasLib.h"
#include "System/Class.h"
#include "Ui/Ui_Viewer.h"

#include "Components/HorizontalBox.h"



void UWRI_Alpha::NativeConstruct()
{
	/**
	V_Viewer->Init(this);
	CreateViewManager(ViewPanels::ViewPanels_MAX);
	ViewManager_->SetViewPanel(ViewPanels::Main, V_Viewer);

	UWRI_AlphaOpt* Opt = UWRI_AlphaOpt::Create(Scope(), this, Views::Setup, 81912345);
	V_Viewer->AddTab(Views::Setup, Opt, *ClassC::WRI_VSetup(), false);
	V_Opts->AddChildToHorizontalBox(Opt);

	Opt = UWRI_AlphaOpt::Create(Scope(), this, Views::Form, 81912345);
	V_Viewer->AddTab(Views::Form, Opt, *ClassC::WRI_VForm(), false);
	V_Opts->AddChildToHorizontalBox(Opt);

	V_Viewer->SwitchView(Views::Setup, false);

	//Opt = UWRI_AlphaOpt::Create(Scope(),81912345);
	//OptsBox_->AddChildToHorizontalBox(Opt);
	//Opt = UWRI_AlphaOpt::Create(Scope(),81912345);
	//OptsBox_->AddChildToHorizontalBox(Opt);

	*/
	Super::NativeConstruct();
}


UWRI_Alpha* UWRI_Alpha::Create(UWorld* InScope, AtlasLibC* InAtlasLib)
{
	UWRI_Alpha* Neu = CreateWidget<UWRI_Alpha>(InScope, ClassC::WRI_Alpha());
	//Neu->SetupAlpha(InScope);
	Neu->Init(InAtlasLib);
	return Neu;
}

void UWRI_Alpha::Init(AtlasLibC* InAtlasLib)
{
	Alpha_ = this;
	OwningView_ = NULL;
	AtlasLib_ = InAtlasLib;
}
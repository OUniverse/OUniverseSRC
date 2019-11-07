//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Alpha.h"
#include "Ui/Writer/WRI_AlphaOpt.h"

#include "Ui/Writer/WRI_VSetup.h"
#include "Ui/Writer/WRI_VForm.h"

#include "System/Babel.h"
#include "System/AtlasLib.h"
#include "System/Class.h"
#include "Ui/Ui_Viewer.h"
#include "Ui/Ui_ViewPanel.h"

#include "Components/HorizontalBox.h"


UWRI_Alpha* UWRI_Alpha::Create(UWorld* InScope, AtlasLibC* InAtlasLib)
{
	UWRI_Alpha* Neu = CreateWidget<UWRI_Alpha>(InScope, ClassC::WRI_Alpha());
	Neu->SetScope(InScope);
	Neu->Init(InAtlasLib);
	return Neu;
	
}
void UWRI_Alpha::Init(AtlasLibC* InAtlasLib)
{
	Alpha_ = this;
	OwningView_ = NULL;
	AtlasLib_ = InAtlasLib;
	CreateViewer();
	Viewer_->SetViewPanel(V_ViewPanel);
	
	UWRI_AlphaOpt* Opt = UWRI_AlphaOpt::Create(Scope(), this, Views::Setup, 81912345);
	Viewer_->AddTab(Views::Setup, Opt, *ClassC::WRI_VSetup(), false);
	V_Opts->AddChildToHorizontalBox(Opt);


	Opt = UWRI_AlphaOpt::Create(Scope(), this, Views::Form, 81912345);
	Viewer_->AddTab(Views::Form, Opt, *ClassC::WRI_VForm(), false);
	V_Opts->AddChildToHorizontalBox(Opt);

	Viewer_->SwitchView(Views::Setup, false);

	//Opt = UWRI_AlphaOpt::Create(Scope(),81912345);
	//OptsBox_->AddChildToHorizontalBox(Opt);
	//Opt = UWRI_AlphaOpt::Create(Scope(),81912345);
	//OptsBox_->AddChildToHorizontalBox(Opt);
}

void UWRI_Alpha::ImbueVSetup(UWRI_VSetup* InVSetup)
{

	InVSetup->Imbue(AtlasLib_);
}

void UWRI_Alpha::ImbueVForm(UWRI_VForm* InVForm)
{

	InVForm->Imbue(AtlasLib_);
}
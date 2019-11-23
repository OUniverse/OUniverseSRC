//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Main.h"
#include "System/Class.h"

#include "Components/HorizontalBox.h"

#include "Ui/Ui_Interactive.h"

#include "Ui/Writer/WRI_AtlasMount.h"
#include "Ui/Writer/WRI_Loadout.h"
#include "Ui/Writer/WRI_AtlasEdit.h"
#include "Ui/Writer/WRI_FormEdit.h"

void UWRI_Main::NativeConstruct()
{
	SetViewPanel(0, V_View);

	SwitchView(0, UWRI_Main::VLoadout);

	V_OptLoadout->SetupInterface(this,Interactives::OptLoadout);
	V_OptAtlas->SetupInterface(this, Interactives::OptAtlas);
	V_OptForm->SetupInterface(this, Interactives::OptForm);

	Super::NativeConstruct();
}

UWRI_Main* UWRI_Main::Create(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	UWRI_Main* Neu = CreateWidget<UWRI_Main>(InParentView->Scope(), ClassC::WRI_Main());
	Neu->Init(InParentView, InAtlasLib);
	return Neu;
}

void UWRI_Main::Init(UUi_View* InParentView, AtlasLibC* InAtlasLib)
{
	StoreParentView(InParentView);

	AddViewPanel(0);

	View_AtlasMount = UWRI_AtlasMount::Create(this);
	AddView(0, UWRI_Main::VAtlasMount, View_AtlasMount);

	View_Loadout = UWRI_Loadout::Create(this,InAtlasLib);
	AddView(0, UWRI_Main::VLoadout, View_Loadout);

	View_AtlasEdit = UWRI_AtlasEdit::Create(this);
	AddView(0, UWRI_Main::VAtlasEdit, View_AtlasEdit);

	View_FormEdit = UWRI_FormEdit::Create(this,InAtlasLib);
	AddView(0, UWRI_Main::VFormEdit, View_FormEdit);
}

void UWRI_Main::Click(UUi_Interactive* Interactive)
{
	int IUID = Interactive->InterfaceUID();
	switch (IUID) {
	case Interactives::OptLoadout:
		SwitchView(0, UWRI_Main::VLoadout);
		break;
	case Interactives::OptAtlas:
		SwitchView(0, UWRI_Main::VAtlasEdit);
		break;
	case Interactives::OptForm:
		SwitchView(0, UWRI_Main::VFormEdit);
		break;
	}
}
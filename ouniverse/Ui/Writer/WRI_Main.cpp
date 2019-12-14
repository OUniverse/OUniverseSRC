//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_Main.h"
#include "System/Class.h"
#include "System/Scope.h"
#include "Ui/UiButton.h"

#include "Ui/Writer/WRI_AtlasMount.h"
#include "Ui/Writer/WRI_Loadout.h"
#include "Ui/Writer/WRI_AtlasEdit.h"
#include "Ui/Writer/WRI_FormEdit.h"


UWRI_Main* UWRI_Main::Create(UUiView* InParentView, AtlasLibC* InAtlasLib)
{
	UWRI_Main* Neu = CreateWidget<UWRI_Main>(ScopeC::World(), ClassC::WRI_Main());
	Neu->Init(InParentView, InAtlasLib);
	return Neu;
}

void UWRI_Main::Init(UUiView* InParentView, AtlasLibC* InAtlasLib)
{
	ConstructView(InParentView);

	OPT_Loadout->SetupButton(Interfaces::OptLoadout, this);
	OPT_AtlasEdit->SetupButton(Interfaces::OptAtlasEdit, this);
	OPT_FormEdit->SetupButton(Interfaces::OptFormEdit, this);



	SwitchView(0, UWRI_Main::Loadout);




	AddViewPanel(0);

	View_AtlasLoad->Init(this);
	AddView(0, UWRI_Main::AtlasLoad, View_AtlasLoad);

	View_Loadout->Init(this, InAtlasLib);
	AddView(0, UWRI_Main::Loadout, View_Loadout);

	View_AtlasEdit->Init(this);
	AddView(0, UWRI_Main::AtlasEdit, View_AtlasEdit);

	View_FormEdit->Init(this,InAtlasLib);
	AddView(0, UWRI_Main::FormEdit, View_FormEdit);
}

void UWRI_Main::EventUi(int WidgetID, int InEventID, UUserWidget* InWidget)
{
	/**
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
	*/
}
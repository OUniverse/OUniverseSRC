//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_FormEdit.h"
#include "System/Scope.h"

#include "UI/Writer/WRI_FormEdit_Le.h"
#include "UI/Writer/WRI_VMainVFormEForm.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Ui/Ui_ScrollBox.h"

#include "System/Class.h"

#include "System/FormQuery.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"


void UWRI_FormEdit::Init(UUiView* InOwningView, AtlasLibC* InAtlasLib)
{
	ConstructView(InOwningView);
	//V_Query->SetupInterface(this, Interactives::IQuery);
	AtlasLib_ = InAtlasLib;
}

void UWRI_FormEdit::FormSelected(FormWrapS InFormWrap)
{
	UWRI_FormEdit_Form* FormPage = UWRI_FormEdit_Form::Create(this, InFormWrap);
	V_Form->AddChild(FormPage);
	(Cast<UCanvasPanelSlot>(FormPage->Slot))->SetAutoSize(true);
	
}

void UWRI_FormEdit::Query()
{
	/**
	StringC QueryText = V_Query->GetText();

	FormRefs_.Clear();
	V_Scroll->ClearChildren();

	FormQueryS* FormQuery = new FormQueryS(QueryText,&FormRefs_);
	AtlasLib_->Query(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWRI_FormEdit_Le* Entry = UWRI_FormEdit_Le::Create(ScopeC::World(), this, FormRefs_[i]);
		V_Scroll->Add(Entry);
	}

	delete FormQuery;
	*/
}
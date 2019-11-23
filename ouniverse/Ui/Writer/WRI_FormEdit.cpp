//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_FormEdit.h"
#include "Ui/Writer/WRI_Alpha.h"

#include "UI/Ui_TextEdit.h"

#include "UI/Writer/WRI_FormEdit_Le.h"
#include "UI/Writer/WRI_VMainVFormEForm.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Ui/Ui_ScrollBox.h"

#include "System/Class.h"

#include "System/FormQuery.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"



void UWRI_FormEdit::NativeConstruct()
{
	V_Query->SetupInterface(this,Interactives::IQuery);
	Super::NativeConstruct();
}

UWRI_FormEdit* UWRI_FormEdit::Create(UUi_View* InOwningView, AtlasLibC* InAtlasLib)
{
	UWRI_FormEdit* Neu = CreateWidget<UWRI_FormEdit>(InOwningView->Scope(), ClassC::WRI_FormEdit());
	Neu->Init(InOwningView, InAtlasLib);
	return Neu;
}

void UWRI_FormEdit::Init(UUi_View* InOwningView, AtlasLibC* InAtlasLib)
{
	StoreParentView(InOwningView);
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
	StringC QueryText = V_Query->GetText();

	FormRefs_.Clear();
	V_Scroll->ClearChildren();

	FormQueryS* FormQuery = new FormQueryS(QueryText,&FormRefs_);
	AtlasLib_->Query(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWRI_FormEdit_Le* Entry = UWRI_FormEdit_Le::Create(OwningView_->Scope(), this, FormRefs_[i]);
		V_Scroll->Add(Entry);
	}

	delete FormQuery;

}

void UWRI_FormEdit::TextCommit(UUi_Interactive* Interactive, int CommitMethod)
{
	Query();
}
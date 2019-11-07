//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VForm.h"
#include "Ui/Writer/WRI_Alpha.h"

#include "UI/Writer/WRI_VFormEntry.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Ui/Ui_ScrollBox.h"

#include "System/Class.h"

#include "System/FormQuery.h"
#include "System/Form_.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"



void UWRI_VForm::InitFromViewer()
{
	CastedView_ = Cast<UWRI_Alpha>(OwningView_);
	CastedView_->ImbueVForm(this);
}

void UWRI_VForm::Imbue(AtlasLibC* InAtlas)
{
	AtlasLib_ = InAtlas;
}

void UWRI_VForm::Query(FString InQueryText)
{
	FormRefs_.Clear();
	V_ScrollBox->ClearChildren();

	FormQueryS* FormQuery = new FormQueryS(InQueryText,&FormRefs_);
	AtlasLib_->Query(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWRI_VFormEntry* Entry = UWRI_VFormEntry::Create(OwningView_->Scope(), this, FormRefs_[i]);
		V_ScrollBox->AddChild(Entry);
	}

	delete FormQuery;

}
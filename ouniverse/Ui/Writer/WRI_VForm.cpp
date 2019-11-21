//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VForm.h"
#include "Ui/Writer/WRI_Alpha.h"

#include "UI/Writer/WRI_VFormEntry.h"
#include "UI/Writer/WRI_VFormEForm.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Ui/Ui_ScrollBox.h"

#include "System/Class.h"

#include "System/FormQuery.h"
#include "System/Form_.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"

#include "Min/DebugM.h"


void UWRI_VForm::NativeConstruct()
{

	Super::NativeConstruct();
}

void UWRI_VForm::FormSelected(FormWrapS InFormWrap)
{
	UWRI_VFormEForm* FormPage = UWRI_VFormEForm::Create(this, InFormWrap);
	V_Form->AddChild(FormPage);
	(Cast<UCanvasPanelSlot>(FormPage->Slot))->SetAutoSize(true);
	
}

void UWRI_VForm::Query(FString InQueryText)
{
	FormRefs_.Clear();
	V_Scroll->ClearChildren();

	FormQueryS* FormQuery = new FormQueryS(InQueryText,&FormRefs_);
	AtlasLib_->Query(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWRI_VFormEntry* Entry = UWRI_VFormEntry::Create(OwningView_->Scope(), this, FormRefs_[i]);
		V_Scroll->Add(Entry);
	}

	delete FormQuery;

}
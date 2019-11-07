//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_VForm.h"
#include "Ui/Writer_Master.h"

#include "UI/Writer_VFormEntry.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/ScrollBox.h"

#include "System/Class.h"

#include "System/FormQuery.h"
#include "System/Form_.h"
#include "Interface/Array.h"

#include "System/AtlasLib.h"

#include "Min/DebugM.h"

UWriter_VForm* UWriter_VForm::Create(UUi_Alpha* InMaster, UCanvasPanel* InPanel)
{
	UWriter_VForm* Neu = CreateWidget<UWriter_VForm>(InMaster->Scope(), ClassC::Writer_VForm());
	Neu->Init(InMaster,InPanel);
	return Neu;
}

void UWriter_VForm::Init(UUi_Alpha* InMaster, UCanvasPanel* InPanel)
{
	CreateViewer();
	SetHubs(InMaster, InMaster);
	CastedMaster_ = Cast<UWriter_Master>(Master_);
	InPanel->AddChild(this);
	SetupForDefaultCanvas();
}

void UWriter_VForm::Need(UScrollBox* InFormScroll, UCanvasPanel* InFormPin)
{
	FormScroll_ = InFormScroll;
	FormPin_ = InFormPin;
}

void UWriter_VForm::Query(FString InQueryText)
{
	FormRefs_.Clear();
	FormScroll_->ClearChildren();
	FormQueryS* FormQuery = new FormQueryS(InQueryText,&FormRefs_);
	AtlasLibC::Get()->Query(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWriter_VFormEntry* Entry = UWriter_VFormEntry::Create(Master_->Scope(), this, FormRefs_[i], FormScroll_);
		Entries_.Emplace(Entry);
	}
	delete FormQuery;

}
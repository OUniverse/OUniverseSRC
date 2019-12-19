//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFormU.h"
#include "Protocol/Writer/WriFormP.h"
#include "Protocol/Writer/Ui/WriFormU_ScrollEntry.h"

#include "Protocol/Writer/Ui/WriFormEditU.h"

#include "Ui/UiScroll.h"
#include "Protocol/Writer/Ui/WriButtonU.h"
#include "Ui/UiEventCodes.h"

#include "Components/EditableText.h"

#include "Interface/String.h"
#include "System/AtlasLib.h"
#include "System/FormData.h"

void UWriForm::NativeConstruct()
{
	Super::NativeConstruct();
	vQuery->OnTextCommitted.AddDynamic(this, &UWriForm::OnTextCommitted);
	vSearch->SetupButton(REG::RSearch,this);
	vNewForm->SetupButton(REG::RNewForm, this);
	vDeleteForm->SetupButton(REG::RDeleteForm, this);
}

void UWriForm::NativeDestruct()
{
	vQuery->OnTextCommitted.RemoveDynamic(this, &UWriForm::OnTextCommitted);
	Super::NativeDestruct();
}

void UWriForm::UiConstruct(WriFormP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}

void UWriForm::OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
        switch (CommitMethod) {
        case ETextCommit::Type::OnEnter:
			Query();
            break;
        case ETextCommit::Type::OnUserMovedFocus:
            // code block
            break;
        }
	
}

void UWriForm::Query()
{
	
	StringC QueryText = vQuery->GetText();

	FormRefs_.Clear();
	vScroll->ClearChildren();

	FormDataQueryC* FormQuery = new FormDataQueryC(QueryText,&FormRefs_);
	AtlasLib_->QueryFormData(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWriForm_ScrollEntry* Entry = UWriForm_ScrollEntry::Create(this, FormRefs_[i]);
		vScroll->AddEntry(Entry);
	}

	delete FormQuery;
}

void UWriForm::OpenForm(FormDataC* InFormData)
{
	vFormEdit->OpenForm(InFormData);
}
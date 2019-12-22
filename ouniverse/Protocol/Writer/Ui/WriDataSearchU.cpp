//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriDataSearchU.h"
#include "Protocol/Writer/Ui/WriButtonU.h"

#include "Protocol/Writer/Ui/WriFormU_ScrollEntry.h"

#include "Protocol/Writer/WriPro.h"
#include "Components/TextBlock.h"
#include "Components/EditableText.h"

#include "System/AtlasLib.h"

#include "Interface/String.h"
#include "System/FormQuery.h"

#include "Ui/UiScroll.h"

void UWriDataSearch::NativeConstruct()
{
	Super::NativeConstruct();

	vDscFilters->SetText(WriterPro::Dict(594783876));
	vDscOptions->SetText(WriterPro::Dict(2012185030));

	vData->SetupButton(REG::RData, this);
	vData->SetTextHash(1872351585);

	vRevision->SetupButton(REG::RRevision, this);
	vRevision->SetTextHash(1446889365);

	vAmmend->SetupButton(REG::RAmmend, this);
	vAmmend->SetTextHash(930130512);

	vNew->SetupButton(REG::RNew, this);
	vNew->SetTextHash(395410456);

	vDelete->SetupButton(REG::RDelete , this);
	vDelete->SetTextHash(1683981082);

	vSearch->SetupButton(REG::RSearch, this);
	vSearch->SetTextHash(2130583320);

	vMaster->SetupButton(REG::RMaster, this);
	vMaster->SetTextHash(195511168);

	vSupport->SetupButton(REG::RSupport, this);
	vSupport->SetTextHash(1561326530);

	vJson->SetupButton(REG::RJson, this);
	vJson->SetTextHash(1058280362);

	vQuery->OnTextCommitted.AddDynamic(this, &UWriDataSearch::OnTextCommitted);
}

void UWriDataSearch::NativeDestruct()
{
	vQuery->OnTextCommitted.RemoveDynamic(this, &UWriDataSearch::OnTextCommitted);
	Super::NativeDestruct();
}

void UWriDataSearch::UiConstruct(WriDataSearchP* InPro, AtlasLibC* InAtlasLib)
{
	Pro_ = InPro;
	AtlasLib_ = InAtlasLib;
}

void UWriDataSearch::OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
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

void UWriDataSearch::Query()
{

	StringC QueryText = vQuery->GetText();

	FormRefs_.Clear();
	vScroll->ClearChildren();

	FormDataQueryC* FormQuery = new FormDataQueryC(QueryText, &FormRefs_);
	AtlasLib_->QueryFormData(FormQuery);

	int L = FormRefs_.Len();
	for (int i = 0; i < L; i++)
	{
		UWriForm_ScrollEntry* Entry = UWriForm_ScrollEntry::Create(this, FormRefs_[i]);
		vScroll->AddEntry(Entry);
	}

	delete FormQuery;
}
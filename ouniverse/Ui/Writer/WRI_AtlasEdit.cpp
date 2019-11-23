//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_AtlasEdit.h"
#include "Ui/Writer/WRI_Alpha.h"

#include "Ui/Ui_TextEdit.h"
#include "Components/TextBlock.h"

#include "System/Atlas.h"

#include "System/Class.h"

#include "Min/DebugM.h"

void UWRI_AtlasEdit::NativeConstruct()
{

	Atlas_ = CastedAlpha_->MasterAtlas_;
	
	
	V_UID->SetText(Atlas_->UID().ToString().ToFText());
	
	V_ID->SetupInterface(this, Interactives::TextID);
	V_Name->SetupInterface(this, Interactives::TextName);
	V_Author->SetupInterface(this, Interactives::TextAuthor);
	V_Website->SetupInterface(this, Interactives::TextWebsite);
	V_Socket->SetupInterface(this, Interactives::TextSocket);

	V_ID->SetText(Atlas_->ID());
	V_Name->SetText(Atlas_->Name());
	V_Author->SetText(Atlas_->Author());
	V_Website->SetText(Atlas_->Website());
	V_Socket->SetText(Atlas_->WebSocket());

	Super::NativeConstruct();
}

UWRI_AtlasEdit* UWRI_AtlasEdit::Create(UUi_View* InOwningView)
{
	UWRI_AtlasEdit* Neu = CreateWidget<UWRI_AtlasEdit>(InOwningView->Scope(), ClassC::WRI_AtlasEdit());
	Neu->Init(InOwningView);
	return Neu;
}

void UWRI_AtlasEdit::Init(UUi_View* InOwningView)
{
	StoreParentView(InOwningView);
	CastedAlpha_ = Cast<UWRI_Alpha>(Alpha());
}

void UWRI_AtlasEdit::TextCommit(UUi_Interactive* Interactive, int CommitMethod)
{
	DBUG("FUCKING COMMITED")
	Atlas_->ID_ = V_ID->GetText();
	Atlas_->Name_ = V_Name->GetText();
	Atlas_->Author_ = V_Author->GetText();
	Atlas_->Website_ = V_Website->GetText();
	Atlas_->WebSocket_ = V_Socket->GetText();

}
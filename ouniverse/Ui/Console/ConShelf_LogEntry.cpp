//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Console/ConShelf_LogEntry.h"
#include "System/Class.h"
#include "System/Scope.h"

#include "System/Logger.h"

#include "Ui/Console/ConShelf_Log.h"
#include "Components/RichTextBlock.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UConShelf_LogEntry::NativeConstruct()
{
	LoggerOutputS LogOutput = Log_->Output();
	V_Text->SetText(LogOutput.Text.ToFText());
	V_Cat->SetText(Log_->GetCategory(LogOutput.Cat));
	V_Index->SetText(StringC(Log_->Index()).ToFText());
	V_Flag->SetBrushFromTexture(View_->FlagFatal);
	Super::NativeConstruct();
}

UConShelf_LogEntry* UConShelf_LogEntry::Create(UConShelf_Log* InView, LoggerEntryC* InLog)
{
	UConShelf_LogEntry* Neu = CreateWidget<UConShelf_LogEntry>(ScopeC::World(), ClassC::ConShelf_LogEntry());
	Neu->Init(InView, InLog);
	return Neu;
}

void UConShelf_LogEntry::Init(UConShelf_Log* InView, LoggerEntryC* InLog)
{
	View_ = InView;
	Log_ = InLog;
}
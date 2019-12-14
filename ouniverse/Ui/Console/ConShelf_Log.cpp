//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Console/ConShelf_Log.h"
#include "System/Logger.h"
#include "Components/ScrollBox.h"

#include "Ui/Console/ConShelf_LogEntry.h"

void UConShelf_Log::Init(UUiView* InParentView, LoggerC* InLog)
{
	Logger_ = InLog;
	ConstructView(InParentView);

}

void UConShelf_Log::ViewOpen_Technical()
{
	int L = Logger_->Num();

	for (int i = 0; i < L; i++)
	{
		V_ScrollBox->AddChild(UConShelf_LogEntry::Create(this, Logger_->GetEntry(i)));
	}
}
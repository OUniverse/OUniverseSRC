//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI.h"
#include "Ui/WriterUi.h"
#include "Protocol/WriterPro.h"

#include "System/Major.h"

WriC::WriC(int InID, WriterPro* InProtocol, UMajor* InMajor) : UiShellC(InID, InProtocol)
{
	Protocol_ = InProtocol;
	Major_ = InMajor;
}

WriterPro* WriC::Protocol()
{
	return Protocol_;
}

void WriC::Activate()
{
	SetAlpha(UWRI::Create(Protocol_, Major_->Atlas()));
	Alpha_->AddToViewport();
}
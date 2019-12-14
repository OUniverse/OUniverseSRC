//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM.h"
#include "Ui/SystemUi.h"
#include "Protocol/SystemPro.h"

#include "System/Major.h"

SymC::SymC(int InID, SystemPro* InProtocol, UMajor* InMajor) : UiShellC(InID,InProtocol)
{
	Protocol_ = InProtocol;
	Major_ = InMajor;
	
}


SystemPro* SymC::Protocol()
{
	return Protocol_;
}

void SymC::Activate()
{
	Alpha_ = USystemUi::Create(Protocol_, Major_->Atlas(), Major_->UserL(), Major_->UserD(), Major_->LoadoutL(), Major_->LoadoutD());
	Alpha_->AddToViewport();
}
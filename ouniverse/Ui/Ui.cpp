//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui.h"
#include "System/Major.h"
#include "System/Class.h"

#include "Ui/Writer/WRI_Alpha.h"

namespace Global
{
	UUi* Ui;
}


UUi* UUi::Create(UMajor* M)
{
	UUi* Neu = CreateWidget<UUi>(M->Scope(), ClassC::U_Ui());
	Neu->Init(M);
	Global::Ui = Neu;
	Neu->AddToViewport();
	return Neu;
}

UUi* UUi::Get()
{
	return Global::Ui;
}

void UUi::Init(UMajor* M)
{
	Major_ = M;
	Scope_ = M->Scope();
}

void UUi::OpenMainMenu()
{
	//MainMenu_->AddToViewport();
}

void UUi::OpenWriter()
{
	Writer_ = UWRI_Alpha::Create(Major_->Scope(), Major_->Atlas());
	Writer_->AddToViewport();
}
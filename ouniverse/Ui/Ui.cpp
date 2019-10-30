//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui.h"
#include "System/Major.h"
#include "System/Class.h"

#include "Ui/Writer_Max.h"

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
	Scope_ = M->Scope();
	Writer_ = CreateWidget<UWriter_Max>(M->Scope(), ClassC::Writer_Max());
}

void UUi::OpenMainMenu()
{
	//MainMenu_->AddToViewport();
}

void UUi::OpenWriter()
{
	Writer_->AddToViewport();
}
//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui.h"
#include "System/Major.h"
#include "System/Class.h"

#include "Ui/System/SYM_Alpha.h"
#include "Ui/Title/TIM_Alpha.h"
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
	ActiveAlpha_ = NULL;
	Major_ = M;
	Scope_ = M->Scope();
}

void UUi::CloseActive()
{
	if (ActiveAlpha_ != NULL)
	{
		ActiveAlpha_->RemoveFromParent();
	}
}

void UUi::OpenSystemMenu()
{
	CloseActive();
	ActiveAlpha_ = USYM_Alpha::Create(Major_->Scope(), this, Major_->Atlas(), Major_->UserL(), Major_->UserD(), Major_->LoadoutL(), Major_->LoadoutD());
	ActiveAlpha_->AddToViewport();
}


void UUi::OpenTitleMenu()
{
	CloseActive();
	ActiveAlpha_ = UTIM_Alpha::Create(Major_->Scope(), this, Major_->UserD(), Major_->LoadoutD(), Major_->Atlas());
	ActiveAlpha_->AddToViewport();
}

void UUi::OpenWriterMenu()
{
	CloseActive();
	ActiveAlpha_ = UWRI_Alpha::Create(Major_->Scope(), this, Major_->Atlas());
	ActiveAlpha_->AddToViewport();
}

void UUi::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	
}
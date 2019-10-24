//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui.h"
#include "Ui/MainMenu.h"

void UUi::Init()
{
	TSoftClassPtr<UUserWidget> WidgetClass = TSoftClassPtr<UUserWidget>(FSoftClassPath("/Game/ui/vm_mainmenu.vm_mainmenu_C"));
	UClass* MyWidgetClass = WidgetClass.LoadSynchronous();
	MainMenu_ = CreateWidget<UMainMenu>(GetGameInstance(), MyWidgetClass);
	MainMenu_->Init();

	//MainMenu_->AddToViewport();
}

void UUi::OpenMainMenu()
{
	MainMenu_->AddToViewport();
}
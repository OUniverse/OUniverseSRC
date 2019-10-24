//Copyright 2015-2019, All Rights Reserved.

#include "System/HudUE.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/GameViewportClient.h"
#include "Blueprint/UserWidget.h"
#include "Ui/Ui.h"
#include "Min/DebugM.h"

void AHudUE::HUD_SUPER_ON()
{

	/**
	SAssignNew(InputNet, SInputCatch).GameHUD(this);
	if (GEngine && GEngine->GameViewport)
	{
		Viewport = GEngine->GameViewport;
		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(InputNet.ToSharedRef()));
	}

	//FSlateApplication::Get().SetKeyboardFocus(InputNet);	

	Ui_ = CreateWidget<UUi>(GetGameInstance(), UUi::StaticClass());
	Ui_->AddToViewport();
	//Ui_->SetVisibility(ESlateVisibility::Visible);


	//FStringClassReference MyWidgetClassRef(TEXT("/Game/uigame/NewWidgetBlueprint.NewWidgetBlueprint_C"));
	//if (UClass * MyWidgetClass = MyWidgetClassRef.TryLoadClass<UUserWidget>())
	//{
	//	UUserWidget* MyWidget = CreateWidget<UUserWidget>(GetGameInstance(), MyWidgetClass);
	//	MyWidget->AddToViewport();
	//}

	*/
	TSoftClassPtr<UUserWidget> WidgetClass = TSoftClassPtr<UUserWidget>(FSoftClassPath("/Game/uigame/NewWidgetBlueprint.NewWidgetBlueprint_C"));
	UClass* MyWidgetClass = WidgetClass.LoadSynchronous();
	UUserWidget* MyWidget = CreateWidget<UUserWidget>(GetGameInstance(), MyWidgetClass);
	MyWidget->AddToViewport();
}

UUi* AHudUE::GetUI()
{
	return Ui_;
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/HudUE.h"
#include "System/Input.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/PlayerController.h"
#include "CohtmlHUD.h"
#include "CohtmlInputActor.h"
#include "SCohtmlInputForward.h"
#include "System/Boot.h"

#include "System/Glass.h"

void AHudUE::PrepareInputs(StringC UiServerPath)
{
	SAssignNew(InputNet,SInput).GameHUD(this);
	if (GEngine && GEngine->GameViewport)
	{
		Viewport = GEngine->GameViewport;

		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(InputNet.ToSharedRef()));
	}

	SetupView((UiServerPath/"ui.html").ToFString(),true,true);

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	ACohtmlInputActor* UiInputActor = GetWorld()->SpawnActor<ACohtmlInputActor>(Location, Rotation, SpawnInfo);
	UiInputActor->Initialize();
	//UiInputActor->AlwaysAcceptMouseInput(true);
	UiInputActor->SetCohtmlViewFocus(GetCohtmlHUD());
	//UiInputActor->SetCohtmlInputFocus(true);
	FSlateApplication::Get().SetKeyboardFocus(InputNet);

	GetCohtmlHUD()->ReadyForBindings.AddDynamic(this, &AHudUE::CoherentReady);

	FInputModeUIOnly Mode;
	Mode.SetWidgetToFocus(InputNet);
	GetOwningPlayerController()->SetInputMode(Mode);


	Glass_ = new GlassC();
	Glass_->Ui_ = GetCohtmlHUD();
	Glass_->NativeInput_ = UiInputActor->GetWidget();

}

void AHudUE::CoherentReady()
{
	//Has to be UFunction for Coherent's PreBind function call.
	UBoot::CoherentReady();
}

void AHudUE::ActivateInputs(InputManager* Input)
{
	InputNet->InputRelay = Input;
}

GlassC* AHudUE::GetGlass()
{
	return Glass_;
}
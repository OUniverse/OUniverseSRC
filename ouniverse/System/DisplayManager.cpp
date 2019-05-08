//Copyright 2015-2019, All Rights Reserved.

#include "System/DisplayManager.h"
#include "System/Input.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/PlayerController.h"
#include "CohtmlHUD.h"
#include "CohtmlInputActor.h"
#include "SCohtmlInputForward.h"
#include "System/Boot.h"

void ADisplayManager::PrepareInputs(FString UiServerPath)
{
	SAssignNew(InputNet,SInput).GameHUD(this);
	if (GEngine && GEngine->GameViewport)
	{
		Viewport = GEngine->GameViewport;

		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(InputNet.ToSharedRef()));
	}
	SetupView(UiServerPath+"ui.html",true,true);

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	ACohtmlInputActor* UiInputActor = GetWorld()->SpawnActor<ACohtmlInputActor>(Location, Rotation, SpawnInfo);
	UiInputActor->Initialize();
	//UiInputActor->AlwaysAcceptMouseInput(true);
	UiNet = UiInputActor->GetWidget();
	UiInputActor->SetCohtmlViewFocus(GetCohtmlHUD());
	//UiInputActor->SetCohtmlInputFocus(true);
	FSlateApplication::Get().SetKeyboardFocus(InputNet);

	GetCohtmlHUD()->ReadyForBindings.AddDynamic(this, &ADisplayManager::CoherentReady);

	FInputModeUIOnly Mode;
	Mode.SetWidgetToFocus(InputNet);
	GetOwningPlayerController()->SetInputMode(Mode);
}


void ADisplayManager::CoherentReady()
{
	//Has to be UFunction for Coherent's PreBind function call.
	UBoot::CoherentReady();
}

void ADisplayManager::ActivateInputs(InputManager* Input)
{
	InputNet->InputRelay = Input;
}

UCohtmlHUD* ADisplayManager::GetUi()
{
	return GetCohtmlHUD();
}

TSharedPtr<class SCohtmlInputForward> ADisplayManager::GetNativeUiInput()
{
	return UiNet;
}
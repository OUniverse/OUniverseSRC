//Copyright 2015-2019, All Rights Reserved.

#include "System/HudUE.h"
#include "System/InputCatch.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/PlayerController.h"
#include "CohtmlHUD.h"
#include "CohtmlInputActor.h"
#include "SCohtmlInputForward.h"
#include "System/Boot.h"

#include "System/Glass.h"


#include "Min/DebugM.h"

void AHudUE::PrepareInputs(HudTypes HudType, bool Alt, const char* AltPath)
{
	FirstBoot = true;
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	ACohtmlInputActor* UiInputActor = GetWorld()->SpawnActor<ACohtmlInputActor>(Location, Rotation, SpawnInfo);
	UiInputActor->Initialize();
	UiInputActor->AlwaysAcceptMouseInput(true);
	UiInputActor->SetCohtmlViewFocus(CoHud_);
	UiInputActor->SetCohtmlInputFocus(true);
	CoBridge_ = UiInputActor->GetWidget();
	CoHud_ = GetCohtmlHUD();

	SAssignNew(InputNet, SInputCatch).GameHUD(this);
	if (GEngine && GEngine->GameViewport)
	{
		Viewport = GEngine->GameViewport;
		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(InputNet.ToSharedRef()));
	}

	//FSlateApplication::Get().SetKeyboardFocus(InputNet);

	GlassC::Create(this);

	if (Alt)
	{
		AltPath_ = true;
		SetView(AltPath);
	}
	else
	{
		AltPath_ = false;

		if (HudType == HudTypes::Main)
		{
			SetView("coui://ui//main.html");
		}
		else if (HudType == HudTypes::Scribe)
		{
			SetView("coui://ui//scribe.html");
		}
	}
}

void AHudUE::ActivateInputs(InputManager* Input)
{
	InputNet->InputRelay = Input;
}

void AHudUE::SetView(const char* InURL)
{
	SetupView(InURL, true, true);
	GetCohtmlHUD()->ReadyForBindings.AddDynamic(this, &AHudUE::ViewReady);
}

void AHudUE::ViewReady()
{
	if (FirstBoot)
	{
			FirstBoot = false;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "View Ready Triggered!");
		//Has to be UFunction for Coherent's PreBind function call.
		OnViewReady_.Trigger();
	
		//IsoBoot is a direct boot to just a loaded UI for easy testing while devoloping UI components.
		if (AltPath_)
		{
			UBoot::UiReadyIsoBoot();
		}
		else
		{
			UBoot::UiReady();
		}
	}
}
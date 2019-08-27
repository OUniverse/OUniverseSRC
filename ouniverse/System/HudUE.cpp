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

void AHudUE::HUD_SUPER_ON(HudTypes HudType)
{

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

	if (HudType == HudTypes::Standard)
	{
		SetView("coui://ui//main.html");
	}
	else if (HudType == HudTypes::Scribe)
	{
		SetView("coui://ui//scribe.html");

	}
	else if (HudType == HudTypes::Iso)
	{
		SetView(Path_.ToChar());
	}
}

void AHudUE::ActivateInputs(InputManager* Input)
{
	InputNet->InputRelay = Input;
}

void AHudUE::SetPath(StringC InPath)
{
	Path_ = InPath;
}

void AHudUE::SetView(const char* InURL)
{
	SetupView(InURL, true, true);
	GetCohtmlHUD()->ReadyForBindings.AddDynamic(this, &AHudUE::ViewReady);
}

void AHudUE::ViewReady()
{
	UBoot::UiReady();
}
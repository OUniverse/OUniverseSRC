//Copyright 2015-2019, All Rights Reserved.

/**
The DisplayManager is an extension to UE4s GameHUD.
- Sets the main UI panel.
- Adds the SInput widget which collects all keypresses and interactions.
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CohtmlGameHUD.h"
#include "Interface/String.h"
#include "HudUE.generated.h"



class UGameViewportClient;
class UInputManager;
class SCohtmlInputForward;

class InputManager;

UCLASS()
class OUNIVERSE_API AHudUE : public ACohtmlGameHUD
{
	GENERATED_BODY()

public:

	void PrepareInputs(StringC UiServerPath);
	void ActivateInputs(InputManager* Input);


	UCohtmlHUD* GetUi();
	TSharedPtr<class SCohtmlInputForward> GetNativeUiInput();

	UFUNCTION()//Has to be UFunction for Coherent's PreBind function call.
	void CoherentReady();

	UGameViewportClient* Viewport;
	TSharedPtr<class SInput> InputNet;
	TSharedPtr<class SCohtmlInputForward> UiNet;
};

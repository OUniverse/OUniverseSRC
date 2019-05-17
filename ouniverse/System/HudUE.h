//Copyright 2015-2019, All Rights Reserved.

/**

## AControlUE

AControlUE is an exension to UE4's AHud.

The Coherent Lab's Ui solution extends this.
This is an extension of Coherent Lab's extension for further control.

#### Tasks
* Sets up the primary UI overlay.
* Outputs a UI bridge singleton to access all of Coherent Lab's functionality.

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

class GlassC;

UCLASS()
class OUNIVERSE_API AHudUE : public ACohtmlGameHUD
{
	GENERATED_BODY()

public:

	void PrepareInputs(StringC UiServerPath);
	void ActivateInputs(InputManager* Input);


	UFUNCTION()//Has to be UFunction for Coherent's PreBind function call.
	void CoherentReady();

	UGameViewportClient* Viewport;
	TSharedPtr<class SInputCatch> InputNet;

	GlassC* Glass_;

	GlassC* GetGlass();

};

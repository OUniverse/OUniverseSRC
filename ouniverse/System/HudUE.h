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
#include "Interface/String.h"
#include "Interface/String.h"

#include "HudUE.generated.h"




class UGameViewportClient;
class UUi;

UCLASS()
class OUNIVERSE_API AHudUE : public AHUD
{
	GENERATED_BODY()

public:


	UGameViewportClient* Viewport;

	void HUD_SUPER_ON();

	UUi* GetUI();

private:

	UPROPERTY()
	UUi* Ui_;

};

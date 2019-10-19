//Copyright 2015-2019, All Rights Reserved.

/**

## ControlUE

AControlUE is an exension to UE4's APlayerController.

> Currently does nothing as the SInputCatch and InputManager are doing most of it's responsibilities.

 */

#pragma once

#include "GameFramework/PlayerController.h"
#include "ControlUE.generated.h"


UCLASS()
class OUNIVERSE_API AControlUE : public APlayerController
{
	GENERATED_BODY()

public:

	AControlUE();

private:

	//UPROPERTY()
	//ACameraManagerUE* CameraManager_;

};
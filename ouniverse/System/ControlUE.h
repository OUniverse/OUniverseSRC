//Copyright 2015-2019, All Rights Reserved.

/**

## ControlUE

AControlUE is an exension to UE4's APlayerController.

> Currently does nothing as the SInputCatch and InputManager are doing most of it's responsibilities.

 */

#pragma once

#include "GameFramework/PlayerController.h"
#include "System/Input.h"
#include "ControlUE.generated.h"


class UMaestro;
class ACameraUE;

UCLASS()
class OUNIVERSE_API AControlUE : public APlayerController
{
	GENERATED_BODY()

public:

	AControlUE();

	void Init(UMaestro* InMaestro);

	void SetCamera(ACameraUE* InCamera);

	ACameraUE* GetCamera();

	InputActionS GetInputAction(bool InPressed);

	UFUNCTION()
	void Test();

	UFUNCTION()
	void Interact_U();

	UFUNCTION()
	void Interact_D();

	UFUNCTION()
	void Member1();

	UFUNCTION()
	void Member2();

	UFUNCTION()
	void Member3();

	UFUNCTION()
	void MoveForward_D();
	UFUNCTION()
	void MoveForward_U();

	UFUNCTION()
	void MoveBack_D();
	UFUNCTION()
	void MoveBack_U();

	UFUNCTION()
	void MoveLeft_D();
	UFUNCTION()
	void MoveLeft_U();

	UFUNCTION()
	void MoveRight_D();
	UFUNCTION()
	void MoveRight_U();

	UFUNCTION()
	void MouseX(float AxisValue);
	UFUNCTION()
	void MouseY(float AxisValue);
	UFUNCTION()
	void MouseW(float AxisValue);

	UFUNCTION()
	void MouseL_D();
	UFUNCTION()
	void MouseL_U();
	UFUNCTION()
	void MouseR_D();
	UFUNCTION()
	void MouseR_U();
	UFUNCTION()
	void MouseM_D();
	UFUNCTION()
	void MouseM_U();

private:

	UPROPERTY()
	UMaestro* Maestro_;

	UPROPERTY()
	ACameraUE* Camera_;

	bool CTR_;
	bool ALT_;
	bool SHIFT_;
	bool HELP_;

	//UPROPERTY()
	//ACameraManagerUE* CameraManager_;

};
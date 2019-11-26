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

	virtual void PlayerTick(float DeltaTime) override;

	virtual void SetupInputComponent() override;

public:

	AControlUE();

	void Init(UMaestro* InMaestro);

	void SetCamera(ACameraUE* InCamera);

	ACameraUE* GetCamera();

	FInputAction GetInputAction(bool InPressed);
	
	UFUNCTION()
	void GPAD_FACE_Down();

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
	void Up_D();
	UFUNCTION()
	void Up_U();

	UFUNCTION()
	void Down_D();
	UFUNCTION()
	void Down_U();

	UFUNCTION()
	void Left_D();
	UFUNCTION()
	void Left_U();

	UFUNCTION()
	void Right_D();
	UFUNCTION()
	void Right_U();

	UFUNCTION()
	void Wheel_D();
	UFUNCTION()
	void Wheel_U();

	UFUNCTION()
	void AxisLX(float AxisValue);
	UFUNCTION()
	void AxisLY(float AxisValue);

	UFUNCTION()
	void AxisRX(float AxisValue);
	UFUNCTION()
	void AxisRY(float AxisValue);

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

	bool ForwardsPressed_;
	bool BackwardsPressed_;
	bool LeftPressed_;
	bool RightPressed_;

	bool LeftDown_;
	//UPROPERTY()
	//ACameraManagerUE* CameraManager_;

};
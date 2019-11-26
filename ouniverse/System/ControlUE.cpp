//Copyright 2015-2019, All Rights Reserved.

#include "System/ControlUE.h"
#include "System/CameraUE.h"
#include "System/Maestro.h"
#include "Min/DebugM.h"

#define PYLON(FUNC,PUSH)FUNC(GetInputAction(PUSH));


AControlUE::AControlUE()
{
	//PlayerCameraManagerClass = ACameraManagerUE::StaticClass();
}


void AControlUE::Init(UMaestro* InMaestro)
{
	Maestro_ = InMaestro;

	ForwardsPressed_ = false;
	BackwardsPressed_ = false;
	LeftPressed_ = false;
	RightPressed_ = false;

	CTR_ = false;
	ALT_ = false;
	SHIFT_ = false;
	HELP_ = false;
		
	InputComponent->BindKey(FKey("Gamepad_FaceButton_Bottom"), IE_Pressed, this, &AControlUE::GPAD_FACE_Down);

	InputComponent->BindKey(FKey("one"), IE_Pressed, this, &AControlUE::Test);
	InputComponent->BindKey(FKey("one"), IE_Released, this, &AControlUE::Test);

	InputComponent->BindKey(FKey("F"), IE_Pressed, this, &AControlUE::Interact_D);
	InputComponent->BindKey(FKey("F"), IE_Released, this, &AControlUE::Interact_U);

	InputComponent->BindKey(FKey("W"), IE_Pressed, this, &AControlUE::Up_D);
	InputComponent->BindKey(FKey("W"), IE_Released, this, &AControlUE::Up_U);

	InputComponent->BindKey(FKey("S"), IE_Pressed, this, &AControlUE::Down_D);
	InputComponent->BindKey(FKey("S"), IE_Released, this, &AControlUE::Down_U);

	InputComponent->BindKey(FKey("A"), IE_Pressed, this, &AControlUE::Left_D);
	InputComponent->BindKey(FKey("A"), IE_Released, this, &AControlUE::Left_U);

	InputComponent->BindKey(FKey("D"), IE_Pressed, this, &AControlUE::Right_D);
	InputComponent->BindKey(FKey("D"), IE_Released, this, &AControlUE::Right_U);

	InputComponent->BindKey(FKey("F1"), IE_Pressed, this, &AControlUE::Member1);
	InputComponent->BindKey(FKey("F2"), IE_Pressed, this, &AControlUE::Member2);
	InputComponent->BindKey(FKey("F3"), IE_Pressed, this, &AControlUE::Member3);

	InputComponent->BindAxisKey(FKey("MouseY"), this, &AControlUE::AxisRX);
	InputComponent->BindAxisKey(FKey("MouseX"), this, &AControlUE::AxisRY);

	InputComponent->BindKey(FKey("LeftMouseButton"), IE_Pressed, this, &AControlUE::MouseL_D);
	InputComponent->BindKey(FKey("LeftMouseButton"), IE_Released, this, &AControlUE::MouseL_U);
	InputComponent->BindKey(FKey("RightMouseButton"), IE_Pressed, this, &AControlUE::MouseR_D);
	InputComponent->BindKey(FKey("RightMouseButton"), IE_Released, this, &AControlUE::MouseR_U);
	InputComponent->BindKey(FKey("MiddleMouseButton"), IE_Pressed, this, &AControlUE::MouseM_D);
	InputComponent->BindKey(FKey("MiddleMouseButton"), IE_Released, this, &AControlUE::MouseM_U);
	
}


void AControlUE::GPAD_FACE_Down()
{
	DBUG("OK")
}

void AControlUE::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("WheelDown", IE_Released, this, &AControlUE::Wheel_D);
	InputComponent->BindAction("WheelUp", IE_Released, this, &AControlUE::Wheel_U);
	
}

void AControlUE::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
	float Axis = 0.0f;

	if (ForwardsPressed_ && BackwardsPressed_)
	{
		Axis = 0.0f;
	}
	else if (ForwardsPressed_)
	{
		Axis = 1.0f;
	}
	else if (BackwardsPressed_)
	{
		Axis = -1.0f;
	}

	AxisLX(Axis);
	Axis = 0.0f;

	if (LeftPressed_ && RightPressed_)
	{
		Axis = 0.0f;
	}
	else if (LeftPressed_)
	{
		Axis = -1.0f;
	}
	else if (RightPressed_)
	{
		Axis = 1.0f;
	}

	AxisLY(Axis);
}

ACameraUE* AControlUE::GetCamera()
{
	return Camera_;
}

void  AControlUE::SetCamera(ACameraUE* InCamera)
{
	Camera_ = InCamera;
	SetViewTarget(InCamera);
}

FInputAction AControlUE::GetInputAction(bool InPressed)
{
	return FInputAction(InPressed, CTR_, ALT_, SHIFT_, HELP_);
}

void AControlUE::Test()
{
	DBUG("OK")
}

void AControlUE::Up_D()
{
	ForwardsPressed_ = true;
	Maestro_->Up(true);
}

void AControlUE::Up_U()
{
	ForwardsPressed_ = false;
	Maestro_->Up(false);
}


void AControlUE::Down_D()
{
	BackwardsPressed_ = true;
	Maestro_->Down(true);
}

void AControlUE::Down_U()
{
	BackwardsPressed_ = false;
	Maestro_->Down(false);
}


void AControlUE::Left_D()
{
	LeftPressed_ = true;
	Maestro_->Left(true);
}

void AControlUE::Left_U()
{
	LeftPressed_ = false;
	Maestro_->Left(false);
}


void AControlUE::Right_D()
{
	RightPressed_ = true;
	Maestro_->Right(true);
}

void AControlUE::Right_U()
{
	RightPressed_ = false;
	Maestro_->Right(false);
}


void AControlUE::Wheel_D()
{
	Maestro_->WheelDown(true);
}

void AControlUE::Wheel_U()
{
	Maestro_->WheelUp(true);
}

void AControlUE::Interact_D()
{
	Maestro_->Interact(true);
}

void AControlUE::Interact_U()
{
	Maestro_->Interact(false);
}

void AControlUE::Member1()
{
	DBUG("M1")
}

void AControlUE::Member2()
{
	DBUG("M2")
}

void AControlUE::Member3()
{
	DBUG("M3")
}

void AControlUE::AxisLX(float AxisValue){	Maestro_->AxisLX(AxisValue); }
void AControlUE::AxisLY(float AxisValue){	Maestro_->AxisLY(AxisValue); }
void AControlUE::AxisRX(float AxisValue){	Maestro_->AxisRX(AxisValue); }
void AControlUE::AxisRY(float AxisValue){	Maestro_->AxisRY(AxisValue); }


void AControlUE::MouseL_D()
{
	Maestro_->MouseL(true);
}

void AControlUE::MouseL_U()
{
	Maestro_->MouseL(false);
}

void AControlUE::MouseR_D()
{
	Maestro_->MouseR(true);
}

void AControlUE::MouseR_U()
{
	Maestro_->MouseL(false);
}

void AControlUE::MouseM_D()
{
	Maestro_->MouseM(true);
}

void AControlUE::MouseM_U()
{
	Maestro_->MouseM(false);
}

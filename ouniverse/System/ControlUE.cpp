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


void AControlUE::Init(MaestroC* InMaestro)
{
	Maestro_ = InMaestro;

	CTR_ = false;
	ALT_ = false;
	SHIFT_ = false;
	HELP_ = false;
		
	InputComponent->BindKey(FKey("one"), IE_Pressed, this, &AControlUE::Test);
	InputComponent->BindKey(FKey("one"), IE_Released, this, &AControlUE::Test);

	InputComponent->BindKey(FKey("F"), IE_Pressed, this, &AControlUE::Interact_D);
	InputComponent->BindKey(FKey("F"), IE_Released, this, &AControlUE::Interact_U);

	InputComponent->BindKey(FKey("W"), IE_Pressed, this, &AControlUE::MoveForward_D);
	InputComponent->BindKey(FKey("W"), IE_Released, this, &AControlUE::MoveForward_U);

	InputComponent->BindKey(FKey("S"), IE_Pressed, this, &AControlUE::MoveBack_D);
	InputComponent->BindKey(FKey("S"), IE_Released, this, &AControlUE::MoveBack_U);

	InputComponent->BindKey(FKey("A"), IE_Pressed, this, &AControlUE::MoveLeft_D);
	InputComponent->BindKey(FKey("A"), IE_Released, this, &AControlUE::MoveLeft_U);

	InputComponent->BindKey(FKey("D"), IE_Pressed, this, &AControlUE::MoveRight_D);
	InputComponent->BindKey(FKey("D"), IE_Released, this, &AControlUE::MoveRight_U);



	InputComponent->BindKey(FKey("F1"), IE_Pressed, this, &AControlUE::Member1);
	InputComponent->BindKey(FKey("F2"), IE_Pressed, this, &AControlUE::Member2);
	InputComponent->BindKey(FKey("F3"), IE_Pressed, this, &AControlUE::Member3);

	InputComponent->BindAxisKey(FKey("MouseX"), this, &AControlUE::MouseX);
	InputComponent->BindAxisKey(FKey("MouseY"), this, &AControlUE::MouseY);
	//InputComponent->BindAxisKey(FKey("MouseWheelSpin"), this, &AControlUE::MouseW);

	InputComponent->BindKey(FKey("LeftMouseButton"), IE_Pressed, this, &AControlUE::MouseL_D);
	InputComponent->BindKey(FKey("LeftMouseButton"), IE_Released, this, &AControlUE::MouseL_U);
	InputComponent->BindKey(FKey("RightMouseButton"), IE_Pressed, this, &AControlUE::MouseR_D);
	InputComponent->BindKey(FKey("RightMouseButton"), IE_Released, this, &AControlUE::MouseR_U);
	InputComponent->BindKey(FKey("MiddleMouseButton"), IE_Pressed, this, &AControlUE::MouseM_D);
	InputComponent->BindKey(FKey("MiddleMouseButton"), IE_Released, this, &AControlUE::MouseM_U);
	
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

InputActionS AControlUE::GetInputAction(bool InPressed)
{
	return InputActionS(InPressed, CTR_, ALT_, SHIFT_, HELP_);
}

void AControlUE::Test()
{
	DBUG("OK")
}

void AControlUE::MoveForward_D()
{
	DBUG("STEP1")
	PYLON(Maestro_->Forward, true)
}

void AControlUE::MoveForward_U()
{
	PYLON(Maestro_->Forward, false)
}


void AControlUE::MoveBack_D()
{
	PYLON(Maestro_->Back, true)
}

void AControlUE::MoveBack_U()
{
	PYLON(Maestro_->Back, false)
}


void AControlUE::MoveLeft_D()
{
	PYLON(Maestro_->Left, true)
}

void AControlUE::MoveLeft_U()
{
	PYLON(Maestro_->Left, false)
}


void AControlUE::MoveRight_D()
{
	PYLON(Maestro_->Right, true)
}

void AControlUE::MoveRight_U()
{
	PYLON(Maestro_->Right, false)
}



void AControlUE::Interact_D()
{
	PYLON(Maestro_->Interact, true)
}

void AControlUE::Interact_U()
{
	PYLON(Maestro_->Interact, false)
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

void AControlUE::MouseX(float AxisValue)
{
	//DBUG("M3")
}

void AControlUE::MouseY(float AxisValue)
{
	//DBUG("M4")
}

void AControlUE::MouseW(float AxisValue)
{
	//DBUG("M4")
}

void AControlUE::MouseL_D()
{
	PYLON(Maestro_->MouseL, true)
}

void AControlUE::MouseL_U()
{
	PYLON(Maestro_->MouseL, false)
}

void AControlUE::MouseR_D()
{
	PYLON(Maestro_->MouseR, true)
}

void AControlUE::MouseR_U()
{
	PYLON(Maestro_->MouseR, false)
}

void AControlUE::MouseM_D()
{
	PYLON(Maestro_->MouseM, true)
}

void AControlUE::MouseM_U()
{
	PYLON(Maestro_->MouseM, false)
}

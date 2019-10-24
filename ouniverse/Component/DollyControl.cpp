//Copyright 2015-2019, All Rights Reserved.

#include "Component/DollyControl.h"
#include "GameFramework/SpringArmComponent.h"

#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

UDollyControl::UDollyControl()
{
	
	Boom_ = CreateDefaultSubobject<USpringArmComponent>(TEXT("ControlCamBoom"));
	Boom_->SetupAttachment(this);
	Boom_->TargetArmLength = 750.f;
	Boom_->SocketOffset = FVector(0.f, 0.f, 0.f);
	Boom_->RelativeLocation = FVector(0.f, 0.f, 200.f);
	Boom_->RelativeRotation = FRotator(0.f, -0.f, 0.f);
	Boom_->TargetArmLength = 400.f;
	Boom_->bEnableCameraLag = true;
	Boom_->CameraLagSpeed = 3.0f;

	Dolly_ = CreateDefaultSubobject<UDolly>(TEXT("ControlDolly"));
	Dolly_->SetupAttachment(Boom_, USpringArmComponent::SocketName);
	Dolly_->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Result_ = Dolly_;
	
}
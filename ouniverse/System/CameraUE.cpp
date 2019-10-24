//Copyright 2015-2019, All Rights Reserved.

#include "System/CameraUE.h"
#include "Camera/CameraComponent.h"
#include "Component/Dolly.h"

ACameraUE::ACameraUE()
{
	CameraComponent_ = CreateDefaultSubobject<UCameraComponent>(TEXT("Cam"));
	CameraComponent_->SetupAttachment(RootComponent);
	CameraComponent_->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));

}


void ACameraUE::SetFOV(float InFOV)
{
	CameraComponent_->SetFieldOfView(InFOV);
}

void ACameraUE::SetGoal(UCameraComponent* InCam)
{
	CameraComponent_->AttachToComponent(InCam, FAttachmentTransformRules::KeepRelativeTransform);
	CameraComponent_->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));

}
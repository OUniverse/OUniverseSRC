//Copyright 2015-2019, All Rights Reserved.

#include "System/CameraUE.h"
#include "Camera/CameraComponent.h"

ACameraUE::ACameraUE()
{
	SceneComponent_ = CreateDefaultSubobject<USceneComponent>(TEXT("Base"));
	SceneComponent_->SetupAttachment(RootComponent);
	CameraComponent_ = CreateDefaultSubobject<UCameraComponent>(TEXT("Cam"));
	CameraComponent_->SetupAttachment(RootComponent);
}


void ACameraUE::SetFOV(float InFOV)
{
	CameraComponent_->SetFieldOfView(InFOV);
}
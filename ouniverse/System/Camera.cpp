//Copyright 2015-2019, All Rights Reserved.

#include "System/Camera.h"
#include "System/ControlUE.h"
#include "System/CameraUE.h"
#include "System/Ether.h"

CameraC::CameraC(EtherC* InEther)
{
	CameraUE_ = InEther->SpawnCamera();
}


void CameraC::Activate(AControlUE* InControl)
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);

	return InControl->SetViewTarget(CameraUE_);
}


void CameraC::SetTransforms(VectorC Location, RotatorC Rotation)
{
	//FVector Location(0.0f, 0.0f, 0.0f);
	//FRotator Rotation(0.0f, 0.0f, 0.0f);

	CameraUE_->SetActorRelativeLocation(Location);
	CameraUE_->SetActorRelativeRotation(Rotation);
	
}

void CameraC::SetFOV(float InFOV)
{
	CameraUE_->SetFOV(InFOV);
}
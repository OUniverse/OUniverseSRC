//Copyright 2015-2019, All Rights Reserved.

#include "System/CameraManager.h"
#include "System/Camera.h"
#include "System/Ether.h"
#include "System/ControlUE.h"
#include "System/CameraUE.h"

CameraManagerC::CameraManagerC(AControlUE* InControl, EtherC* InEther)
{
	Control_ = InControl;
	CameraManager_ = Control_->GetCamera();
	Ether_ = InEther;
}


void CameraManagerC::CreatePrimaryCamera()
{
	Primary_ = new CameraC();
	Primary_->AssignCameraActor(Ether_->SpawnCamera());

	Control_->SetViewTarget(Primary_->CameraActor());
}
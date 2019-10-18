//Copyright 2015-2019, All Rights Reserved.

#include "System/Camera.h"

#include "System/ControlUE.h"

#include "System/Ether.h"
#include "Min/MajorM.h"

CameraC::CameraC()
{

}

void CameraC::AssignCameraActor(ACameraUE* InCameraActor)
{
	CameraUE_ = InCameraActor;
}

ACameraUE* CameraC::CameraActor()
{
	return CameraUE_;
}


//Copyright 2015-2019, All Rights Reserved.

#include "System/ControlUE.h"
#include "System/CameraManagerUE.h"

#include "Min/DebugM.h"

AControlUE::AControlUE()
{
	PlayerCameraManagerClass = ACameraManagerUE::StaticClass();
}

ACameraManagerUE* AControlUE::GetCamera()
{
	DBUG("THIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIS WAS FUUUUUUUUUUUUUCKING MADE!!!!!!!!!!!!")
	CameraManager_ = Cast<ACameraManagerUE>(PlayerCameraManager);
	return CameraManager_;
}
//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Mathz/Vector.h"
#include "Mathz/Rotator.h"

class ACameraUE;
class AControlUE;
class EtherC;

class CameraC
{

public:

	CameraC(EtherC* InEther);

	ACameraUE* CameraUE_;

	void Activate(AControlUE* InControl);

	void SetFOV(float InFOV);

	void SetTransforms(FVector Location, FRotator Rotation);

};
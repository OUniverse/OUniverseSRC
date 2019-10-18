//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/Array.h"

class AControlUE;
class ACameraManagerUE;
class CameraC;
class EtherC;

class CameraManagerC
{

public:

	CameraManagerC(AControlUE* InControl, EtherC* InEther);

	void CreatePrimaryCamera();

private:

	EtherC* Ether_;

	AControlUE* Control_;

	ACameraManagerUE* CameraManager_;
	
	TArray<CameraC*> Cameras_;

	CameraC* Primary_;
};
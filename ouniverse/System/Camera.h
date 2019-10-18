//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

class AControlUE;
class ACameraManagerUE;
class ACameraUE;

class CameraC
{

public:

	CameraC();
	
	void AssignCameraActor(ACameraUE* InCameraActor);

	ACameraUE* CameraUE_;

	ACameraUE* CameraActor();

};
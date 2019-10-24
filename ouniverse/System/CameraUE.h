//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "GameFramework/Actor.h"
#include "CameraUE.generated.h"

class UCameraComponent;

UCLASS()
class OUNIVERSE_API ACameraUE : public AActor
{
	GENERATED_BODY()

public:

	ACameraUE();

	void SetFOV(float InFOV);

	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent_;

	void SetGoal(UCameraComponent* InCam);
};
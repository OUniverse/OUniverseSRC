//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "GameFramework/Actor.h"
#include "CameraUE.generated.h"

UCLASS()
class OUNIVERSE_API ACameraUE : public AActor
{
	GENERATED_BODY()

public:

	ACameraUE();

	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent_;

	UPROPERTY(Category = CameraActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneComponent_;

	
};
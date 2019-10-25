//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "System/Input.h"
#include "MovementIO.generated.h"

class A3dCharacter;

UCLASS(Blueprintable)
class OUNIVERSE_API UIoMovement : public UInputSchema
{

	GENERATED_BODY()

public:

	static UIoMovement* Create(A3dCharacter* InCharacter);

	virtual ~UIoMovement() {};

	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void ActionForward(bool& Result);

private:


	A3dCharacter* Character_;

	void Init(A3dCharacter* InCharacter);

	virtual InputReplyS Forward(InputActionS InIA) override;	
	bool ActionForward_Internal();
};
//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "System/Input.h"
#include "CharacterIO.generated.h"

class ACharacter3D;

UCLASS(Blueprintable)
class OUNIVERSE_API UIoCharacter : public UInputSchema
{

	GENERATED_BODY()

public:

	static UIoCharacter* Create(ACharacter3D* InCharacter);

	virtual ~UIoCharacter() {};

	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void ActionForward(bool& Result);

private:


	ACharacter3D* Character_;

	void Init(ACharacter3D* InCharacter);

	virtual InputReplyS Forward(InputActionS InIA) override;	
	bool ActionForward_Internal();
};
//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/ObjA.h"
#include "System/Input.h"

#include "CharacterA.generated.h"

class CharacterD;
class ACharacter3D;
class UCharacterInput;

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEvent_OnAxisXL, float, AxisValue);

UCLASS(Blueprintable)
class OUNIVERSE_API UCharacterA : public UObjA
{
	GENERATED_BODY()

public:

	UCharacterA() {};

	static UCharacterA* Create(CharacterD* InForm);

	virtual AActor* Spawn() override;

	void Possess();

	UFUNCTION(BlueprintPure, Category = "Actual")
	ACharacter3D* Character3D();
	
	UPROPERTY()
	ACharacter3D* Character3D_;


	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
	void LookX(float AxisValue);
	void TurnY(float AxisValue);
	void Zoom(float AxisValue);

	//UPROPERTY(BlueprintAssignable)
	//FEvent_OnAxisXL OnTimeUpdated;

	UPROPERTY()
	UCharacterInput* Input_;


};
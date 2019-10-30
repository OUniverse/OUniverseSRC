//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "System/Input.h"
#include "CharacterInput.generated.h"

UCLASS(Blueprintable)
class OUNIVERSE_API UCharacterInput : public UObject
{
	GENERATED_BODY()

public:

	UCharacterA* Character_;

	static UCharacterInput* Create(UCharacterA* InChar);

	void Init(UCharacterA* InChar);

	UFUNCTION(BlueprintCallable)
	void MoveX(float AxisValue);
	
	UFUNCTION(BlueprintCallable)
	void MoveY(float AxisValue);

	UFUNCTION(BlueprintCallable)
	void TurnY(float AxisValue);

	UFUNCTION(BlueprintCallable)
	void LookX(float AxisValue);

	UFUNCTION(BlueprintCallable)
	void Zoom(float AxisValue);

	bool WheelUp(bool Down);
	UFUNCTION(BlueprintNativeEvent)
	void OnWheelUp(bool Down, bool& Handled);

	bool WheelDown(bool Down);
	UFUNCTION(BlueprintNativeEvent)
	void OnWheelDown(bool Down, bool& Handled);

	bool AxisLX(float AxisValue);
	UFUNCTION(BlueprintNativeEvent)
	void OnAxisLX(float AxisValue, bool& Handled);

	bool AxisLY(float AxisValue);
	UFUNCTION(BlueprintNativeEvent)
	void OnAxisLY(float AxisValue, bool& Handled);

	bool AxisRX(float AxisValue);
	UFUNCTION(BlueprintNativeEvent)
	void OnAxisRX(float AxisValue, bool& Handled);

	bool AxisRY(float AxisValue);
	UFUNCTION(BlueprintNativeEvent)
	void OnAxisRY(float AxisValue, bool& Handled);
};
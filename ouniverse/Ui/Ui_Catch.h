//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Relay.h"
#include "Ui_Catch.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Catch : public UUi_Relay
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void Clicked();
	UFUNCTION(BlueprintCallable)
	void Pressed();
	UFUNCTION(BlueprintCallable)
	void Released();
	UFUNCTION(BlueprintCallable)
	void Hovered();
	UFUNCTION(BlueprintCallable)
	void Unhovered();

};
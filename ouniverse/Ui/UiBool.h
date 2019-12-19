//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiBase.h"
#include "UiBool.generated.h"


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiBool : public UUiBase
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void BoolOnBP();
	UFUNCTION(BlueprintImplementableEvent)
	void BoolOffBP();
};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Protocol/Writer/Ui/WriButtonU.h"
#include "WriButtonOptU.generated.h"

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriButtonOpt : public UWriButton
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void UnsavedBP();
	UFUNCTION(BlueprintImplementableEvent)
	void UnsavedCancelBP();

};
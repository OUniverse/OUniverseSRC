//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriDataLoadU.generated.h"

class WriDataLoadP;


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriDataLoad : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriDataLoadP* InPro);

	WriDataLoadP* Pro_;

	UFUNCTION(BlueprintCallable)
	void AnimationComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void LoadStart();

	UFUNCTION(BlueprintImplementableEvent)
	void LoadEnd();

};
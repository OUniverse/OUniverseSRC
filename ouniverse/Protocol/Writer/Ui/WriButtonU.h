//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiButton.h"
#include "WriButtonU.generated.h"

class UTextBlock;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriButton : public UUiButton
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void SetTextHash(int InTextHash);


	UFUNCTION(BlueprintCallable)
	void Require(UTextBlock* InText);

	UTextBlock* vText;
};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriBrassU.generated.h"

struct WriBrassS;
class UTexture2D;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriBrass : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;


	void Display(WriBrassS* InBrassData);

	void Clear();

	UFUNCTION(BlueprintImplementableEvent)
	void BrassUpdateBP(UTexture2D* InTexture, const FText& InTitle, const FText& InDescription);
	UFUNCTION(BlueprintImplementableEvent)
	void BrassClearBP();
};
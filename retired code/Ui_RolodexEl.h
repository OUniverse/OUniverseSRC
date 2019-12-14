//Copyright 2015-2019, All Rights Reserved.

/**
Base widget which manages the entire UI.
 */


#pragma once

#include "Blueprint/UserWidget.h"
#include "UI_RolodexEl.generated.h"

class USizeBox;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_RolodexEl : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Size;

	void Require(USizeBox* InSizeBox);

	void SetHeight(float InHeight);

};
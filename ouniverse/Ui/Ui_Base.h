//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Ui_Base.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Base : public UUserWidget
{

	GENERATED_BODY()

public:


	int BaseID;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BaseOpen"))
	void BaseOpen();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BaseClose"))
	void BaseClose();

	virtual float Height() { return 0.0f; };
	virtual float Width() { return 0.0f; };

};
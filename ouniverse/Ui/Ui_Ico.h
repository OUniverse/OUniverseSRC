//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Blueprint/UserWidget.h"
#include "Ui_Ico.generated.h"



UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Ico : public UUserWidget
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void Select();

	UFUNCTION(BlueprintCallable)
	void Deselect();

	
};
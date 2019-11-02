//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Blueprint/UserWidget.h"
#include "Ui_Opt.generated.h"


class UUi_View;


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Opt : public UUserWidget
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ViewUID_;

	bool Deselect_Internal();

	UFUNCTION(BlueprintCallable)
	void Deselect();

	bool Select_Internal();

	UFUNCTION(BlueprintCallable)
	void Select();

	
};
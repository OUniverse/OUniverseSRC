//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Interface.h"
#include "Ui_Button.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Button : public UUi_Interface
{

	GENERATED_BODY()

public:

	bool Deselect_Internal();

	UFUNCTION(BlueprintCallable)
	void Deselect();

	bool Select_Internal();

	UFUNCTION(BlueprintCallable)
	void Select();

};
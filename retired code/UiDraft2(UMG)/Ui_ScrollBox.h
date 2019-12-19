//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiEl.h"
#include "Ui_ScrollBox.generated.h"

class UScrollBox;
class UUserWidget;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API UUi_ScrollBox: public UUiEl
{

	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	UScrollBox* V_Scroll;

	void Add(UUserWidget* InChild);

	void ClearChildren();

};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ubc.h"
#include "Ui_ScrollBox.generated.h"

class UScrollBox;
class UUserWidget;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_ScrollBox: public UUbc
{

	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	UScrollBox* V_Scroll;

	void Add(UUserWidget* InChild);

	void ClearChildren();

};
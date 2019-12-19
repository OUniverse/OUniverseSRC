//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "UiScrollEntry.generated.h"

class UUiBase;
class UUiScroll;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiScrollEntry : public UUiFocus
{

	GENERATED_BODY()

public:

	void SetParentScroll(UUiScroll *InScroll);

	UUiScroll* OwningScroll_;

};
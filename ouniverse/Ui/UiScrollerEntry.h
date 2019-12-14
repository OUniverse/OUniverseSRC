//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "UiScrollerEntry.generated.h"

class UUiBaseNew;
class UUiScroller;

UCLASS(Blueprintable)
class OUNIVERSE_API UUiScrollerEntry : public UUiFocus
{

	GENERATED_BODY()

public:

	void SetParentScroll(UUiScroller* InScroll);

	UUiScroller* OwningScroll_;

};
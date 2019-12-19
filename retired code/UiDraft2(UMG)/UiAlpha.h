//Copyright 2015-2019, All Rights Reserved.

/**
Every major UI menu's base widget is an extension of "Alpha".
It provides functionality for the Ui to swap them out and holds some variables and common interfaces for all children.
 */

#pragma once

#include "Ui/UiView.h"
#include "UiAlpha.generated.h"



UCLASS(Blueprintable)
class OUNIVERSE_API UUiAlpha : public UUiView
{

	GENERATED_BODY()

public:

	void ConstructAlpha();

};
//Copyright 2015-2019, All Rights Reserved.

/**
Every major UI menu's base widget is an extension of "Alpha".
It provides functionality for the Ui to swap them out and holds some variables and common interfaces for all children.
 */

#pragma once

#include "Ui/Ui_View.h"
#include "Ui_Alpha.generated.h"

class UUi;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Alpha : public UUi_View
{

	GENERATED_BODY()

private:



public:

	void SetupAlpha(UWorld* InScope, UUi* InUi);
		
	UWorld* Scope();

	UWorld* Scope_;

	UUi* Ui_;

};
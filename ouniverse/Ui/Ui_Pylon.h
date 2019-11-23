//Copyright 2015-2019, All Rights Reserved.

/**
Extension of the BaseWidget. Can receive action events (such as input actions like click, and mouse movements) from a nested interactive element.
 */

#pragma once

#include "Ui/Ui_El.h"
#include "Interface/String.h"
#include "Ui_Pylon.generated.h"

class UUi_Bool;
class UUi_Interactive;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Pylon : public UUi_El
{

	GENERATED_BODY()

public:

	virtual void Click(UUi_Interactive* Interactive) {};
	virtual void PreciseClick(UUi_Interactive* Interactive) {};
	virtual void MouseDown(UUi_Interactive* Interactive) {};
	virtual void MouseUp(UUi_Interactive* Interactive) {};
	virtual void MouseEnter(UUi_Interactive* Interactive) {};
	virtual void MouseExit(UUi_Interactive* Interactive) {};
	virtual void MouseMove(UUi_Interactive* Interactive) {};
	virtual void TextChanged(UUi_Interactive* Interactive) {};
	virtual void TextCommit(UUi_Interactive* Interactive, int CommitMethod) {};


};
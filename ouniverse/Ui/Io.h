//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


class UCohtmlHUD;
class UiManager;

class OUNIVERSE_API Io
{

	friend UiManager;

protected:

	Io(UCohtmlHUD* InUi);

	virtual ~Io() {};
	UCohtmlHUD* Ui;
	UiManager* UiManagerPTR;

	virtual void InitializeBinds();
	virtual void Activate();
	virtual void Deactivate();
	virtual void King();
};
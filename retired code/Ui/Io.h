//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


class GlassC;
class UiManager;

class OUNIVERSE_API Io
{

	friend UiManager;

protected:

	Io(GlassC* InGlass);

	virtual ~Io() {};
	GlassC* Glass_;
	UiManager* UiManagerPTR;

	virtual void InitializeBinds();
	virtual void Activate();
	virtual void Deactivate();
	virtual void King();
};
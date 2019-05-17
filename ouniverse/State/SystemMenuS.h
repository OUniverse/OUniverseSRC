//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "CoreMinimal.h"
#include "State/State.h"



class UiC;
class UserLib;

class OUNIVERSE_API SystemMenuState : public State
{
	friend StateManager;

private:

	SystemMenuState(UiC* InUi, UserLib* InUser);

	UiC* UiP;
	UserLib* UserP;

	virtual void Activate() override;

};
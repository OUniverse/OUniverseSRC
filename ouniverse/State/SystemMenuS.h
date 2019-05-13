//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "CoreMinimal.h"
#include "State/State.h"



class UiManager;
class UserLib;

class OUNIVERSE_API SystemMenuState : public State
{
	friend StateManager;

private:

	SystemMenuState(UiManager* InUi, UserLib* InUser);

	UiManager* UiP;
	UserLib* UserP;

	virtual void Activate() override;

};
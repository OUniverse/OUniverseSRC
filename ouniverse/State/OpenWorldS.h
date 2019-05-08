//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "CoreMinimal.h"
#include "State/State.h"


class OUNIVERSE_API OpenWorldState : public State
{

	friend StateManager;

private:

	virtual void Activate() override;
};
//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "CoreMinimal.h"
#include "State/State.h"


class OUNIVERSE_API CreationState : public State
{

	friend StateManager;

private:

	virtual void Activate() override;

};
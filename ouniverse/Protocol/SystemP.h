//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/ProtocolP.h"

class UiC;
class UserLibC;

class OUNIVERSE_API SystemP : public ProtocolP
{
	friend ProtocolManager;

private:

	SystemP();

	bool AtlasLocked_;

	virtual void Activate() override;

};
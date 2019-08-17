//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "Protocol/ProtocolP.h"


class OUNIVERSE_API ScribeP : public ProtocolP
{

	friend ProtocolManager;

private:

	virtual void Activate() override;

};
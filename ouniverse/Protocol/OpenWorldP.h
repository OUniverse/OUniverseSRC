//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/ProtocolP.h"


class OUNIVERSE_API OpenWorldP : public ProtocolP
{

	friend MaestroC;

private:

	virtual void Activate() override;
};
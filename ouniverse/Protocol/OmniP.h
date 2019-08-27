//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "Protocol/ProtocolP.h"

class MajorC;

class OUNIVERSE_API OmniP : public ProtocolP
{
	
	friend ProtocolManager;


public:


private:


	OmniP(MajorC* InMajor);

	virtual void Activate() override;

};
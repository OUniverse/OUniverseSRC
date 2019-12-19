//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"

class UUi;
class USymTokens;

class OUNIVERSE_API SymTokensP : public ProtocolC
{

public: 

	SymTokensP(int InID);
		
	USymTokens* SymTokensUI_;

};
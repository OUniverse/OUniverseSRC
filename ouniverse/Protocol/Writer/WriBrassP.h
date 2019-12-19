//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"

class WriterPro;
class UWriBrass;

class OUNIVERSE_API WriBrassP : public ProtocolC
{

public: 

	WriBrassP(int InID);

	void ConstructUi(UWriBrass* InView);

	UWriBrass* View_;
};
//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class WriterPro;
class UWriFooter;

class WriBrassP;

class OUNIVERSE_API WriFooterP : public ProtocolC, public InputC
{

public: 

	WriFooterP(int InID, WriterPro* InPro);

	void ConstructUi(UWriFooter* InView);


	UWriFooter* View_;

	WriterPro* Pro_;
	WriBrassP* WriBrass_;

	static enum Pro {
		PBrass,
	};

};
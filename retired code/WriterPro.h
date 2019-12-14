//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "System/Input.h"
#include "Protocol/Protocol.h"

class UWRI;
class UMajor;
class WriC;

class OUNIVERSE_API WriterPro : public ProtocolC, public InputUiC
{


	friend MaestroC;

public:

	static WriterPro* Create(int InID, UMajor* InMajor);

	WriterPro(int InID, UMajor* InMajor);


private:

	WriterPro();

	UMajor* Major_;
	UWRI* Alpha_;
	WriC* Shell_;

};
//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Int.h"

class FormF;


struct FormPilotS
{

	FormPilotS();
	FormPilotS(U32 InUID, StringC InID, int InType);

public: 

	U32 UID();
	StringC ID();
	int Type();

private:

	U32	UID_;
	StringC ID_;
	int Type_;
};
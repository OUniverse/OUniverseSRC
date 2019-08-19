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
	FormPilotS(FormF* InForm);

public: 

	U64 UID();
	StringC ID();
	int Type();

private:

	U64	UID_;
	StringC ID_;
	int Type_;
};
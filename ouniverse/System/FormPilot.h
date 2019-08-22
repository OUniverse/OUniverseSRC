//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Int.h"

#include "System/DuetUID.h"

class FormF;


struct FormPilotS
{

	FormPilotS();
	FormPilotS(DuetUID InDuet, StringC InID, int InType);

public: 

	AtlasUID AtlasUID();
	FormUID FormUID();
	StringC ID();
	int Type();

private:

	DuetUID DuetUID_;
	StringC ID_;
	int Type_;
};
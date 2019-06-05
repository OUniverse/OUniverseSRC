//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Header.h"
#include "System/Atlas.h"

class AtlasC;

class DocD
{

public: 

	DocD() {};

	DocD(AtlasC* InAtlas);

protected:

	ScribeS Scribe_;
	int UID_;
	AtlasC* Atlas_;
	
};
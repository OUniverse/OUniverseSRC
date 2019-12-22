//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Int.h"

class DataD;
class AtlasC;

struct FormWrapS
{

	FormWrapS() {};
	FormWrapS(AtlasC* InAtlas, DataD* InForm);

	AtlasC* Atlas();
	DataD* Form();
	

private:

	AtlasC* Atlas_;
	DataD* Form_;
	

};
//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Int.h"

class FormF;
class AtlasC;

struct FormWrapS
{

	FormWrapS() {};
	FormWrapS(AtlasC* InAtlas, FormF* InForm);

	AtlasC* Atlas();
	FormF* Form();
	

private:

	AtlasC* Atlas_;
	FormF* Form_;
	

};
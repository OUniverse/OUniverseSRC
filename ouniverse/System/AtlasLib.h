//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"


class AtlasC;

class AtlasLibC
{

public:

	AtlasLibC();
	AtlasC* operator[](U64 InValue);

private:

	enum Types {
		Form,
		Ref,
		Object,
		TYPES_MAX,
	};

	int Num_;

	MapC<U64, AtlasC*> Lib_;

};
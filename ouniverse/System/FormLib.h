//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Json.h"

#include "Form/FormF.h"


class AtlasLibC;
struct JsonS;

class FormLibC
{

public:

	FormLibC();


	FormF* operator[](U32 InValue);

	void AddList(JsonS* InJ);

	void LinkBoost(AtlasLibC* InAtlasLib);
	void LinkExtra(AtlasLibC* InAtlasLib);

private:

	enum Types {
		Form,
		Ref,
		Object,
		TYPES_MAX,
	};

	int Num_;

	ArrayC<FormF* (*)(JsonS&)> FactoryArray;

	MapC<U32, FormF*> PreLib_;

};
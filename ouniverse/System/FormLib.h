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

	static const char* K_TYPE;

	FormLibC();

	int Len();

	FormF* operator[](U32 InValue);

	void Add(FormF* NewForm);

	void AddList(JsonS* InJ);

	void LinkBoost(AtlasLibC* InAtlasLib);
	
	void LinkExtra(AtlasLibC* InAtlasLib);

private:

	enum Types {
		Error,
		Form,
		Ref,
		Object,
		Actor,
		Epoch,
		Actra,
		TYPES_MAX,
	};

	int Len_;

	ArrayC<FormF* (*)(JsonS&)> FactoryArray;

	MapC<U32, FormF*> Lib_;

};
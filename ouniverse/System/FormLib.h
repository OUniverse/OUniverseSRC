//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Json.h"

#include "Form/FormF.h"

#include "System/FormPilot.h"
#include "System/FormQuery.h"

class AtlasLibC;
class AtlasC;
struct JsonS;

class FormLibC
{

public:

	FormLibC(AtlasC* InOwningAtlas);

	~FormLibC();

	int Len();

	AtlasC* OwningAtlas;

	FormF* Get(U32 InValue);

	FormF* operator[](U32 InValue);

	void Add(FormF* NewForm);

	void AddList(JsonS* InJ);

	void LinkBoost(AtlasLibC* InAtlasLib);
	
	void LinkExtra(AtlasLibC* InAtlasLib);
		
	void Query(FormQueryS* InQuery);

	FormWrapS GetFormWrap(U32 InForm);

	StringC Serialize();

	JsonS ToJson();

private:

	int Len_;

	ArrayC<FormF* (*)(JsonS&)> FactoryArray;

	MapC<U32, FormF*> Lib_;

};
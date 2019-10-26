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

	void Demarshal();

	AtlasC* OwningAtlas;

	FormF* Get(FormUID InUID);

	bool Try(FormUID InUID, FormF*& InForm);

	void Add(FormF* InForm);

	void AddList(JsonS* InJ);
		
	void Query(FormQueryS* InQuery);

	FormWrapS GetFormWrap(FormUID InForm);

	StringC Serialize();

	JsonS ToJson();

private:

	int Len_;

	ArrayC<FormF* (*)(JsonS&)> FactoryArray;

	MapC<FormUID, FormF*> Lib_;

};
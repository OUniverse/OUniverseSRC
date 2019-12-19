//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Json.h"

#include "Form/FormF.h"

#include "System/FormQuery.h"

class AtlasLibC;
class AtlasC;
struct JsonS;
class FormDataC;



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

	void AddData(AtlasC* InAtlas, FormF* InForm);

	void AddList(JsonS* InJ, AtlasC* InAtlas, int InDataMode);
		
	void Query(FormQueryS* InQuery);

	void QueryFormData(FormDataQueryC* InQuery);

	FormWrapS GetFormWrap(FormUID InForm);

	StringC Serialize();

	JsonS ToJson();

private:

	int Len_;
	int FormDataLen_;

	ArrayC<FormF* (*)(JsonS&)> FactoryArray;

	MapC<FormUID, FormF*> Lib_;

	MapC<FormUID, FormDataC*> FormDataLib_;

};
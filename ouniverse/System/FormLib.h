//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Json.h"

#include "Data/DataD.h"

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

	DataD* Get(FormUID InUID);

	bool Try(FormUID InUID, DataD*& InForm);

	void Add(DataD* InForm);

	void AddData(AtlasC* InAtlas, DataD* InForm);

	void AddList(JsonS* InJ, AtlasC* InAtlas, int InDataMode);
		
	void Query(FormQueryS* InQuery);

	void QueryFormData(FormDataQueryC* InQuery);

	FormWrapS GetFormWrap(FormUID InForm);

	StringC Serialize();

	JsonS ToJson();

private:

	int Len_;
	int FormDataLen_;

	ArrayC<DataD* (*)(JsonS&)> FactoryArray;

	MapC<FormUID, DataD*> Lib_;

	MapC<FormUID, FormDataC*> FormDataLib_;

};
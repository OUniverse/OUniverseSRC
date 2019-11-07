//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Json.h"

#include "System/FormQuery.h"

class AtlasLibC;
class AtlasC;
class AmendmentC;

struct JsonS;

class AmendmentLibC
{

public:

	static const char* K_UID;
	static const char* K_TYPE;

	AmendmentLibC(AtlasC* InOwningAtlas, AtlasLibC* InAtlasLib);

	int Len();

	AtlasC* OwningAtlas_;

	AmendmentC* Get(StringC InValue);

	AmendmentC* operator[](StringC InValue);

	void Add(AmendmentC* InAmendment);

	void AddList(JsonS* InJ);

	void Query(FormQueryS* InQuery);

	FormWrapS GetFormWrap(U32 InRevision);

	StringC Serialize();

	JsonS ToJson();


private:

	AtlasLibC* AtlasLib_;

	int Len_;

	MapC<StringC, AmendmentC*> Lib_;

};
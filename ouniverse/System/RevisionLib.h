//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Json.h"

#include "System/FormPilot.h"
#include "System/FormQuery.h"

class AtlasLibC;
class AtlasC;
class RevisionC;

struct JsonS;

class RevisionLibC
{

public:

	RevisionLibC(AtlasC* InOwningAtlas, AtlasLibC* InAtlasLib);

	int Len();

	AtlasC* OwningAtlas_;

	RevisionC* Get(StringC InValue);

	RevisionC* operator[](StringC InValue);

	void Add(RevisionC* InRevision);

	void AddList(JsonS* InJ);

	void Query(FormQueryS* InQuery);

	FormWrapS GetFormWrap(U32 InRevision);
	
	StringC Serialize();

	JsonS ToJson();

private:

	AtlasLibC* AtlasLib_;

	int Len_;

	MapC<StringC, RevisionC*> Lib_;

};
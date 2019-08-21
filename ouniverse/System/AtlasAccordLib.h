//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "System/AtlasAccord.h"
#include "Interface/String.h"
#include "Interface/Array.h"
#include "Interface/Json.h"


class AtlasAccordLibC
{

public:

	AtlasAccordLibC();

	~AtlasAccordLibC();

	int Len();

	AtlasAccordC* Get(int Ix);

	void Add(AtlasAccordC* InAccord);

	void AddList(JsonS* InJ);
	
	StringC Serialize();

	JsonS ToJson();

private:

	int Len_;

	ArrayC<AtlasAccordC*> Lib_;
};
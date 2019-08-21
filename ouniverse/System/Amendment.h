//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"

class AmendmentC
{

public:

	static AmendmentC* Create(JsonS& InJ);

	AmendmentC(JsonS& InJ);

	virtual ~AmendmentC() {};

	StringC Serialize();

	JsonS ToJson();

	void Update(JsonS& InJ);

	StringC UID();

private:

	U64 TargetAtlasUID_;
	U32 TargetUID_;
	StringC UID_;

	JsonS Json_;
};
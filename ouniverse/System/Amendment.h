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


	virtual int Type() { return 1; };

	static AmendmentC* Create(JsonS& InJ);

	AmendmentC(JsonS& InJ);

	virtual ~AmendmentC() {};

	StringC Serialize();

	JsonS ToJson();

	virtual JsonS ToJsonInternal(JsonS& S);

	void Update(JsonS& InJ);

	StringC UID();

private:

	U64 TAUID_;
	U32 TUID_;
	StringC UID_;

	JsonS Json_;
};
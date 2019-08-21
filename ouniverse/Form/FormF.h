//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"


class FormF
{

public:

	static FormF* Create(JsonS& InJ);

	FormF(JsonS& InJ);

	virtual int Type();
		
	virtual void Marshal();
		
	virtual ~FormF() {};

	U32 UID();
	
	StringC ID();
		
	StringC Serialize();

	JsonS ToJson();

	virtual JsonS ToJsonInternal(JsonS& S);

	void Update(JsonS& InJ);

protected:

	U32 UID_;
	StringC ID_;
	JsonS Json_;
};
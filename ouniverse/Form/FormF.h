//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"


class FormF
{
	static const char* K_UID;
	static const char* K_ID;

public:


	virtual int Type() { return 1; };

	static FormF* Create(JsonS& InJ);

	FormF(JsonS& InJ);
		
	virtual void Marshal();
		
	virtual ~FormF() {};

	U32 UID();
	
	StringC ID();
		
protected:

	U32 UID_;
	StringC ID_;
	JsonS J;		
};
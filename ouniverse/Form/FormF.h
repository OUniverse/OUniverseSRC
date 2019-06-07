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

public:

	static const char* K_NAME;

	static FormF* Create(JsonS& InJ);

	FormF(JsonS& InJ);
		
	virtual void Marshal();
		
	virtual ~FormF() {};

	U32 UID();

protected:

	U32 UID_;
	JsonS J;		
};
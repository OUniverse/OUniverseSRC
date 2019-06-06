//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"

class FactoryF;

class FormF
{
	static const char* K_UID;

	friend FactoryF;

public:

	static const char* K_NAME;

	static FormF Create();

	FormF();
		
	virtual void Marshal(JsonS* J);
		
	virtual ~FormF() {};

	U32 UID();

protected:

	U32 UID_;
	StringC Serialized;		
};
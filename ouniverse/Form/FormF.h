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
	friend FactoryF;

public:

	static FormF Create();

	FormF();
		
	virtual void Marshal(JsonS* J);
		
	virtual ~FormF() {};

protected:

	StringC Serialized;	
	
	
};
//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"

#include "System/FormPilot.h"

class FormF
{
	static const char* K_UID;

public:

	static const char* K_NAME;

	virtual int Type_() { return 1; };

	static FormF* Create(JsonS& InJ);

	FormF(JsonS& InJ);
		
	virtual void Marshal();
		
	virtual ~FormF() {};

	U32 UID();
	
	StringC ID();

	FormPilotS AsFormPilot();
		
protected:

	U32 UID_;
	StringC ID_;
	JsonS J;		
};
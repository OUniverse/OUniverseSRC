//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"

#include "System/FormUID.h"

class FormF
{

public:

	static FormF* Create(JsonS& InJ);

	FormF();

	void Setup(JsonS& InJ);

	virtual int Type();
		
	virtual void Demarshal();
		
	virtual ~FormF() {};

	FormUID UID();
	
	StringC ID();
		
	StringC Serialize();

	JsonS ToJson();

	virtual JsonS ToJsonInternal(JsonS& S);

	void Update(JsonS& InJ);

protected:

	FormUID UID_;
	StringC ID_;
	JsonS Json_;
};
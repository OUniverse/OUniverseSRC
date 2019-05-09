//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "CoreMinimal.h"

class PayloadC;
struct JsonS;

class FormF
{
	friend PayloadC;

protected:

	FormF();
	uint32 UID;
	FString Serialized;
	static FormF* Create();
	
	virtual void Marshal(JsonS* J);
	virtual ~FormF() {};
};
//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "CoreMinimal.h"
#include <rapidjson/document.h>

class Payload;

class FormF
{
	friend Payload;

protected:

	FormF();
	uint32 UID;
	FString Serialized;
	static FormF* Create();
	
	virtual void Marshal(rapidjson::Document* J);
	virtual ~FormF() {};
};
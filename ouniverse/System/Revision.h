//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"

#include "Form/FormF.h"

class RevisionC
{


public:

	static RevisionC* Create(JsonS& InJ);

	RevisionC(JsonS& InJ);
	
	virtual ~RevisionC() {};

	StringC Serialize();

	JsonS ToJson();

	void Update(JsonS& InJ);

	StringC UID();

private:

	U64 TargetAtlasUID_;
	U32 TargetUID_;
	StringC UID_;
	
	FormF* Form_;
	JsonS Json_;
};
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


	virtual int Type() { return 1; };

	static RevisionC* Create(JsonS& InJ);

	RevisionC(JsonS& InJ);
	
	virtual ~RevisionC() {};

	StringC Serialize();

	JsonS ToJson();

	virtual JsonS ToJsonInternal(JsonS& S);

	void Update(JsonS& InJ);

	StringC UID();

private:

	U64 TAUID_;
	U32 TUID_;
	StringC UID_;
	
	FormF* Form_;
	JsonS Json_;
};
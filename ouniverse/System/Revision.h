//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"

#include "System/DuetUID.h"
#include "Data/DataD.h"

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

	DuetUID Target_;
	StringC UID_;
	
	DataD* Form_;
	JsonS Json_;
};
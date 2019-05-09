//Copyright 2015-2019, All Rights Reserved.

/**
Object Form: Base level of anything that is placed in the world.
 */

#pragma once
#include "Form/FormF.h"

class ObjectF : public FormF
{
	friend PayloadC;

public:

	static FormF* Create();
	ObjectF();

	virtual void Marshal(JsonS* J) override;
};
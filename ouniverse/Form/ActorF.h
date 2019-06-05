//Copyright 2015-2019, All Rights Reserved.

/**
Object Form: Base level of anything that is placed in the world.
 */

#pragma once

#include "Form/ObjectF.h"


class ActorF : public ObjectF
{
	friend FactoryF;

public:

	static FormF Create();
	ActorF();

	virtual void Marshal(JsonS* J) override;
};
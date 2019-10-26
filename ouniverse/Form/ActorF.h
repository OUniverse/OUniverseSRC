//Copyright 2015-2019, All Rights Reserved.

/**
Actor Form: A placement in 3D space.
 */

#pragma once

#include "Form/ObjectF.h"

class ActorF : public ObjectF
{

public:

	ActorF();
	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;
};
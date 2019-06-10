//Copyright 2015-2019, All Rights Reserved.

/**
Object Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"

class ObjectF : public FormF
{

public:

	ObjectF(JsonS& InJ);
	static ObjectF* Create(JsonS& InJ);

	virtual void Marshal() override;
};
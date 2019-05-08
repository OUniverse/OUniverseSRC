//Copyright 2015-2019, All Rights Reserved.

/**
Object Form: Base level of anything that is placed in the world.
 */

#pragma once
#include "Form/Form.h"

class ObjectF : public FormF
{
	friend Payload;

public:

	static FormF* Create();
	ObjectF();

	virtual void Marshal(rapidjson::Document* J) override;
};
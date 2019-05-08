//Copyright 2015-2019, All Rights Reserved.

/**
Ref Form: A placement in 3D space.
 */

#pragma once

#include "Form/Form.h"

class RefF : public FormF
{

public:

	RefF();
	static FormF* Create();

	virtual void Marshal(rapidjson::Document* J) override;
};
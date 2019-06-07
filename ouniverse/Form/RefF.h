//Copyright 2015-2019, All Rights Reserved.

/**
Ref Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"

class RefF : public FormF
{

public:

	RefF(JsonS& InJ);
	static RefF* Create(JsonS& InJ);

	virtual void Marshal() override;
};
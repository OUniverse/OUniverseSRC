//Copyright 2015-2019, All Rights Reserved.

/**
Epoch Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"

class EpochF : public FormF
{

public:

	EpochF(JsonS& InJ);
	static EpochF* Create(JsonS& InJ);

	virtual void Marshal() override;
};
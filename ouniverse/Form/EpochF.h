//Copyright 2015-2019, All Rights Reserved.

/**
Ref Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"

class EpochF : public FormF
{

	friend FactoryF;

public:

	EpochF(StringC Jser);
	static EpochF Create(StringC Jser);

	virtual void Marshal(JsonS* J) override;

private:

	StringC Name_;

};
//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"

class ActraF : public FormF
{

public:

	ActraF(JsonS& InJ);
	static ActraF* Create(JsonS& InJ);

	virtual void Marshal() override;
};
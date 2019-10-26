//Copyright 2015-2019, All Rights Reserved.

/**
Ref Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"

class RefF : public FormF
{

public:

	RefF();
	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

};
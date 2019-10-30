//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"
#include "Interface/String.h"

class UAreaA;

class AreaF : public FormF
{

public:

	AreaF();

	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

	UAreaA* CreateActual();

};
//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"
#include "Interface/String.h"

class URegionA;

class RegionF : public FormF
{

public:

	RegionF();

	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

	URegionA* CreateActual();

};
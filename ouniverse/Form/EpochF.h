//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"
#include "Interface/String.h"

class UEpochA;

class EpochF : public FormF
{

public:

	EpochF();

	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

	UEpochA* CreateActual();

};
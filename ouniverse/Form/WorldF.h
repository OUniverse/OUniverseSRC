//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Data/DataD.h"
#include "Interface/String.h"

class UWorldA;

class WorldF : public DataD
{

public:

	WorldF();

	static DataD* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

	UWorldA* CreateActual();

};
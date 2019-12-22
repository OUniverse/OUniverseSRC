//Copyright 2015-2019, All Rights Reserved.

/**
Object Form: A placement in 3D space.
 */

#pragma once

#include "Data/DataD.h"

class ObjF : public DataD
{

public:

	ObjF();
	static DataD* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

};
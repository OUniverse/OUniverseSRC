//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Data/DataD.h"
#include "Interface/String.h"


class FlagF : public DataD
{

public:

	FlagF();

	static DataD* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

};
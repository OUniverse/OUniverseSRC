//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Data/DataD.h"
#include "Interface/String.h"

class UCharacterA;

class CharacterD : public DataD
{

public:

	CharacterD();

	static DataD* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

	UCharacterA* CreateEx();

	StringC Name_;

	PolyC* PolyInternal(PolyObjectC* InPoly) override;

};
//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"
#include "Interface/String.h"

class UCharacterA;

class CharacterF : public FormF
{

public:

	CharacterF();

	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

	UCharacterA* CreateEx();

	StringC Name_;
};
//Copyright 2015-2019, All Rights Reserved.

/**
Actra Form: A placement in 3D space.
 */

#pragma once

#include "Form/FormF.h"


class UCharacterE;

class CharacterF : public FormF
{

public:

	CharacterF();

	static FormF* Create(JsonS& InJ);

	virtual int Type() override;

	virtual void Demarshal() override;

	UCharacterE* CreateEx();

	StringC Name_;
};
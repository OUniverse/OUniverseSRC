//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Form/FormD.h"
#include "inttypes.h"

class UCharacterE;


class OUNIVERSE_API CharacterD : public FormD
{

public:

	CharacterD();

	UCharacterE* CreateEx();

private:

	uint8_t Level;
	

};
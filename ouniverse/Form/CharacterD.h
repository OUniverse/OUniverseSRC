//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"


class UCharacterE;


class OUNIVERSE_API CharacterD : public UObject
{

public:

	CharacterD();

private:

	UCharacterE* CreateEx();

};
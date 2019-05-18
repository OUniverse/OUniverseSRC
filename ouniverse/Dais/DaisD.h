//Copyright 2015-2019, All Rights Reserved.

/**

## Dais

A Dais is similar to a playthrough.
It could represent a character that is being played by the user.
It is broader however in that it represents the user's character and the party around them.

**Creator:** KernelK
**Holder:** KernelK

 */

#pragma once

#include "Interface/String.h"

class DaisPreD;

class OUNIVERSE_API DaisD
{

private:



public:

	DaisD(DaisPreD* InDaisPre);

	void Promote();

	void Demote();

};
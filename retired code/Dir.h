//Copyright 2015-2019, All Rights Reserved.

/**

## Dir

**Struct:** DirS

Represents a directory in an OOP sense.

* Allows paths to be passed around and dynamically updated if changed.
* Has a few helper functions for directory management built in.

> Possibly this should be changed to a class.

*/

#pragma once

#include "CoreMinimal.h"
#include "Interface/String.h"
#include "Interface/Array.h"

struct DirS
{

	DirS(StringC InPath);	

	StringC Get();

	void Make();

private:

	StringC Path_;
};
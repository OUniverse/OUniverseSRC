//Copyright 2015-2019, All Rights Reserved.

/**

## PreDais

An abbreviated pilot PreDais that is not fully loaded to go easier on the character/dais select screen.

**Creator:** KernelK
**Holder:** KernelK

 */

#pragma once

#include "Kernel/SaveFileK.h"


class DaisPreD : public SaveFileK
{

private:

	int UID_;

	bool Valid_;

public:

	DaisPreD(StringC InFileName, StringC InPath);

	void Crunch(StringC InFileName);

	int GetUID();

	void Preload();
};
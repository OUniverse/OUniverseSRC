//Copyright 2015-2019, All Rights Reserved.

/**

## Scribe

**Struct:**  ScribeS

On write all documents are given a version number which is updated only if the read mechanism of the script were changed.
This allows OUniverse to adapt and update in realtime to outdated documents allowing for the engine to improve into the future while maintaining backwards compatability.

*/

#pragma once

#include "Interface/String.h"

struct ScribeS
{

public:

	ScribeS();
	ScribeS(StringC InLine);

	bool Valid();
	int Get();

private:

	int Value_;

};
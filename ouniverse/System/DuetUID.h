//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"

#include "System/AtlasUID.h"
#include "System/FormUID.h"
// UINT32

class DuetUID
{

public:

	DuetUID();

	DuetUID(AtlasUID InAtlasUID, FormUID InFormUID);

	DuetUID(StringC InS);

	AtlasUID Atlas();
	AtlasUID Atlas() const;

	FormUID Form();
	FormUID Form() const;

	bool operator<(const DuetUID& l) const;

	bool operator!=(DuetUID In);

	bool operator==(DuetUID In);
	
	StringC String();

private:

	AtlasUID AtlasUID_;
	FormUID FormUID_;
	
};
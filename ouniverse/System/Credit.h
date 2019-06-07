//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"

class CreditLibC;
struct JsonS;

class CreditC
{
	friend CreditLibC;
	
public: 

	U64 UID();

	bool Valid();

	StringC ID_;
	StringC Name_;
	StringC Icon_;
	StringC Desc_;
	StringC Author_;
	StringC Website_ ;
	StringC Date_;

	U64 Recency;

private:

	U64 UID_;

	bool Valid_;

	CreditC(U64 InUID, JsonS* InJ);

};
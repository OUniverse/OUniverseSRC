//Copyright 2015-2019, All Rights Reserved.

/**
Credit
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"


class CreditC;
class LoadoutC;

class CreditLibC
{

public:

	CreditLibC();

	CreditC* operator[](U64 InValue);

	CreditC* At(int Index);

	void Add(U64 InUID, CreditC* InCredit);

	int Len();

	bool Try(U64 InUID, CreditC* Out);
	
private:

	int Len_;
	
	MapC<U64, CreditC*> Lib_;

};
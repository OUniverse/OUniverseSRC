//Copyright 2015-2019, All Rights Reserved.

#include "System/Credit.h"
#include "Interface/Json.h"


CreditC::CreditC(U64 InUID, JsonS* InJ)
{
	UID_ = InUID;
	Valid_ = false;

	Valid_ = true;
}

bool CreditC::Valid()
{
	return Valid_;
}

U64 CreditC::UID()
{
	return UID_;
}
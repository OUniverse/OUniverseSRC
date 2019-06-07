//Copyright 2015-2019, All Rights Reserved.

#include "System/CreditLib.h"
#include "System/Credit.h"

#include "System/Log.h"

CreditLibC::CreditLibC()
{
	Len_ = 0;
}


CreditC* CreditLibC::operator[](U64 InValue)
{
	return Lib_[InValue];
}

CreditC* CreditLibC::At(int Index)
{
	return Lib_.At(Index);
}

void CreditLibC::Add(U64 InUID, CreditC* InCredit)
{
	Len_++;
	Lib_.Add(InUID, InCredit);
}

int CreditLibC::Len()
{
	return Len_;
}

bool CreditLibC::Try(U64 InUID, CreditC* Out)
{
	return Lib_.Try(InUID, Out);
}
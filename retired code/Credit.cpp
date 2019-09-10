//Copyright 2015-2019, All Rights Reserved.

#include "System/Credit.h"
#include "Interface/Json.h"

const char* CreditC::K_UID			= "u";
const char* CreditC::K_ID			= "i";
const char* CreditC::K_AUTHORITY	= "a";
const char* CreditC::K_ITERATION	= "t";


const char* CreditC::FILE_NAME = "_credits.cred";


CreditC::CreditC(JsonS* InJ)
{
	Valid_ = false;


	Update(InJ);
	Valid_ = true;

}

bool CreditC::Valid()
{
	return Valid_;
}

void CreditC::Update(JsonS* InJ)
{

}

void CreditC::Compare(JsonS* InJ)
{
	int Iteration = InJ->Int(CreditC::K_ITERATION);
	int Authority = InJ->Int(CreditC::K_AUTHORITY);
	
	if (Authority > Authority_)
	{
		Update(InJ);
		return;
	}

	if (Iteration == Iteration_)
	{
		return;
	}
	else if (Iteration > Iteration_)
	{
		if (Authority >= Authority_)
		{
			Update(InJ);
			return;
		}
	}
}
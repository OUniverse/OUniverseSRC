//Copyright 2015-2019, All Rights Reserved.

#include "System/FormQuery.h"
#include "Form/FormF.h"



bool FormQueryBooleanS::Valid(FormF* InForm)
{
	return false;
}


FQB_ID_CaseInsensitiveS::FQB_ID_CaseInsensitiveS(StringC InQueryID)
{
	QueryID_ = InQueryID.ToLower();
}

bool FQB_ID_CaseInsensitiveS::Valid(FormF* InForm)
{
	if (InForm->ID().ToLower().Contains(QueryID_))
	{
		return true;
	}
	
	return false;

}


FormQueryS::FormQueryS(StringC InQuery)
{

}

void FormQueryS::Scan(FormF* InForm)
{

}
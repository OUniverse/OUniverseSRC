//Copyright 2015-2019, All Rights Reserved.

#include "Form/EpochF.h"
#include "Interface/Json.h"

EpochF::EpochF(JsonS& InJ) : FormF(J)
{

}

FormF* EpochF::Create(JsonS& InJ)
{ 
	return new EpochF(InJ);
}


void EpochF::Marshal()
{
	FormF::Marshal();
}
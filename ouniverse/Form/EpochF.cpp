//Copyright 2015-2019, All Rights Reserved.

#include "Form/EpochF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"

int EpochF::Type()
{
	return FormTypesC::Types::Epoch;
}

EpochF::EpochF(JsonS& InJ) : FormF(Json_)
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
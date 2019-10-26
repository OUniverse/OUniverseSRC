//Copyright 2015-2019, All Rights Reserved.

#include "Form/EpochF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"

int EpochF::Type()
{
	return FormTypesC::Types::Epoch;
}

EpochF::EpochF()
{

}

FormF* EpochF::Create(JsonS& InJ)
{ 
	FormF* Obj = new EpochF();
	Obj->Setup(InJ);
	return Obj;
}


void EpochF::Demarshal()
{
	FormF::Demarshal();
}
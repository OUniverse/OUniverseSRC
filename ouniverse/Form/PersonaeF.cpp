//Copyright 2015-2019, All Rights Reserved.

#include "Form/PersonaeF.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int PersonaeF::Type()
{
	return FormTypesC::Types::Area;
}


PersonaeF::PersonaeF()
{

}

DataD* PersonaeF::Create(JsonS& InJ)
{
	DataD* Obj = new PersonaeF();
	Obj->Setup(InJ);
	return Obj;
}

void PersonaeF::Demarshal()
{
	DataD::Demarshal();
}

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

FormF* PersonaeF::Create(JsonS& InJ)
{
	FormF* Obj = new PersonaeF();
	Obj->Setup(InJ);
	return Obj;
}

void PersonaeF::Demarshal()
{
	FormF::Demarshal();
}

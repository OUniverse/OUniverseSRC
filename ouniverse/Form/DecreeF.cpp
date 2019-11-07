//Copyright 2015-2019, All Rights Reserved.

#include "Form/DecreeF.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int DecreeF::Type()
{
	return FormTypesC::Types::Area;
}


DecreeF::DecreeF()
{

}

FormF* DecreeF::Create(JsonS& InJ)
{
	FormF* Obj = new DecreeF();
	Obj->Setup(InJ);
	return Obj;
}

void DecreeF::Demarshal()
{
	FormF::Demarshal();
}

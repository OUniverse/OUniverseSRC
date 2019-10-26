//Copyright 2015-2019, All Rights Reserved.

#include "Form/RefF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"

int RefF::Type()
{
	return FormTypesC::Types::Ref;
}


RefF::RefF()
{

}

FormF* RefF::Create(JsonS& InJ)
{ 
	FormF* Obj = new RefF();
	Obj->Setup(InJ);
	return Obj;
}


void RefF::Demarshal()
{
	FormF::Demarshal();
}
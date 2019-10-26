//Copyright 2015-2019, All Rights Reserved.

#include "Form/ObjectF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"

int ObjectF::Type()
{
	return FormTypesC::Types::Object;
}

ObjectF::ObjectF()
{

}

FormF* ObjectF::Create(JsonS& InJ)
{ 
	FormF* Obj = new ObjectF();
	Obj->Setup(InJ);
	return Obj;
}


void ObjectF::Demarshal()
{
	FormF::Demarshal();
}
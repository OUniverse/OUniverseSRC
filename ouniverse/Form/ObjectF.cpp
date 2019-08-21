//Copyright 2015-2019, All Rights Reserved.

#include "Form/ObjectF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"

int ObjectF::Type()
{
	return FormTypesC::Types::Object;
}

ObjectF::ObjectF(JsonS& InJ) : FormF(Json_)
{

}

FormF* ObjectF::Create(JsonS& InJ)
{ 
	return new ObjectF(InJ);
}


void ObjectF::Marshal()
{
	FormF::Marshal();
}
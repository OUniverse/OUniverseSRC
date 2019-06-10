//Copyright 2015-2019, All Rights Reserved.

#include "Form/ObjectF.h"
#include "Interface/Json.h"

ObjectF::ObjectF(JsonS& InJ) : FormF(J)
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
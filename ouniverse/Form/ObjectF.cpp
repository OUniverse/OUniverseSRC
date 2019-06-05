//Copyright 2015-2019, All Rights Reserved.

#include "Form/ObjectF.h"
#include "Interface/Json.h"


ObjectF::ObjectF(){}

FormF ObjectF::Create() { return ObjectF(); }

void ObjectF::Marshal(JsonS* J)
{
	FormF::Marshal(J);
}
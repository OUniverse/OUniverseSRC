//Copyright 2015-2019, All Rights Reserved.

#include "Form/Object.h"

class PayloadC;


ObjectF::ObjectF(){}

FormF* ObjectF::Create() { return new ObjectF(); }

void ObjectF::Marshal(rapidjson::Document* J)
{
	FormF::Marshal(J);
}
//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActorF.h"
#include "Interface/Json.h"


ActorF::ActorF(){}

FormF ActorF::Create() { return ActorF(); }

void ActorF::Marshal(JsonS* J)
{
	ObjectF::Marshal(J);
}
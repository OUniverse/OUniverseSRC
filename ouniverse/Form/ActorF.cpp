//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActorF.h"
#include "Interface/Json.h"


ActorF::ActorF(){}

FormF* ActorF::Create() { return new ActorF(); }

void ActorF::Marshal(JsonS* J)
{
	FormF::Marshal(J);
}
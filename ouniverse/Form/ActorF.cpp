//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActorF.h"
#include "Interface/Json.h"

ActorF::ActorF(JsonS& InJ) : ObjectF(J)
{

}

FormF* ActorF::Create(JsonS& InJ)
{ 
	return new ActorF(InJ);
}


void ActorF::Marshal()
{
	ObjectF::Marshal();
}
//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActorF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"


int ActorF::Type()
{
	return FormTypesC::Types::Actor;
}

ActorF::ActorF(JsonS& InJ) : ObjectF(Json_)
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
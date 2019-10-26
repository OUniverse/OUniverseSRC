//Copyright 2015-2019, All Rights Reserved.

#include "Form/ActorF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"


int ActorF::Type()
{
	return FormTypesC::Types::Actor;
}

ActorF::ActorF()
{

}

FormF* ActorF::Create(JsonS& InJ)
{ 
	FormF* Obj = new ActorF();
	Obj->Setup(InJ);
	return Obj;
}


void ActorF::Demarshal()
{
	ObjectF::Demarshal();
}
//Copyright 2015-2019, All Rights Reserved.

#include "Form/WorldF.h"
#include "Form/WorldA.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int WorldF::Type()
{
	return FormTypesC::Types::World;
}

UWorldA* WorldF::CreateActual()
{
	return UWorldA::Create(this);
}

WorldF::WorldF()
{

}

FormF* WorldF::Create(JsonS& InJ)
{ 
	FormF* Obj = new WorldF();
	Obj->Setup(InJ);
	return Obj;
}

void WorldF::Demarshal()
{
	FormF::Demarshal();
}

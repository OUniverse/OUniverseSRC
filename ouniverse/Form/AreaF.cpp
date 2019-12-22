//Copyright 2015-2019, All Rights Reserved.

#include "Form/AreaF.h"
#include "Form/AreaA.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int AreaF::Type()
{
	return FormTypesC::Types::Area;
}

UAreaA* AreaF::CreateActual()
{
	return UAreaA::Create(this);
}

AreaF::AreaF()
{

}

DataD* AreaF::Create(JsonS& InJ)
{
	DataD* Obj = new AreaF();
	Obj->Setup(InJ);
	return Obj;
}

void AreaF::Demarshal()
{
	DataD::Demarshal();
}

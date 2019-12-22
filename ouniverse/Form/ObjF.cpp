//Copyright 2015-2019, All Rights Reserved.

#include "Form/ObjF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"

int ObjF::Type()
{
	return FormTypesC::Types::Obj;
}

ObjF::ObjF()
{

}

DataD* ObjF::Create(JsonS& InJ)
{ 
	DataD* Obj = new ObjF();
	Obj->Setup(InJ);
	return Obj;
}


void ObjF::Demarshal()
{
	DataD::Demarshal();
}
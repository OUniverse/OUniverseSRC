//Copyright 2015-2019, All Rights Reserved.

#include "Form/RefF.h"
#include "System/FormTypes.h"
#include "Interface/Json.h"

int RefF::Type()
{
	return FormTypesC::Types::Ref;
}


RefF::RefF(JsonS& InJ) : FormF(Json_)
{

}

FormF* RefF::Create(JsonS& InJ)
{ 
	return new RefF(InJ);
}


void RefF::Marshal()
{
	FormF::Marshal();
}
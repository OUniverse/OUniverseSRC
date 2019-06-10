//Copyright 2015-2019, All Rights Reserved.

#include "Form/RefF.h"
#include "Interface/Json.h"

RefF::RefF(JsonS& InJ) : FormF(J)
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
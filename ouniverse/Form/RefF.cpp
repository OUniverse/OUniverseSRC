//Copyright 2015-2019, All Rights Reserved.

#include "Form/RefF.h"
#include "Interface/Json.h"

RefF::RefF(){}
FormF* RefF::Create() { return new RefF(); }
void RefF::Marshal(JsonS* J)
{
	FormF::Marshal(J);
}
//Copyright 2015-2019, All Rights Reserved.

#include "Form/FactoryF.h"

#include "Form/FormF.h"
#include "Form/RefF.h"
#include "Form/ObjectF.h"



FactoryF::FactoryF()
{

	FAC.Init(Types::MAX, NULL);
	FAC[Types::Form]		= FormF::Create;
	FAC[Types::Ref]		= RefF::Create;
	FAC[Types::Object]	= ObjectF::Create;
	
}
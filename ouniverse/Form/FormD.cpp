//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormD.h"
#include "Form/FormE.h"

UFormE* FormD::CreateEx()
{
	return UFormE::Create(this);
}

FormD::FormD()
{

}
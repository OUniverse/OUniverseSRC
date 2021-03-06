//Copyright 2015-2019, All Rights Reserved.

#include "Mathz/Modulo.h"
#include <math.h>

ModuloFloatS::ModuloFloatS()
{
	Modulus_ = 0.0f;
	Quotient_ = 0;
	PercentRemainder_ = 0.0f;
}

ModuloFloatS::ModuloFloatS(float InTotal, float InDiv)
{
	float DivResult = InTotal / InDiv;
	Quotient_ = floor(DivResult);		
	PercentRemainder_ = DivResult - Quotient_;
	Modulus_ = (PercentRemainder_)*InDiv;
}

float ModuloFloatS::Modulus()
{
	return Modulus_;
}

int ModuloFloatS::Quotient()
{
	return Quotient_;
}

float ModuloFloatS::PercentRemainder()
{
	return PercentRemainder_;
}

ModuloFloatS ModuloC::ModuloFloat(float InTotal, float InDiv)
{
	return ModuloFloatS(InTotal, InDiv);
}


int ModuloC::Quotient(float InTotal, float InDiv)
{
	return floor(InTotal / InDiv);
}
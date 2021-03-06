//Copyright 2015-2019, All Rights Reserved.


#pragma once


struct ModuloFloatS
{

public:

	ModuloFloatS();
	ModuloFloatS(float InTotal, float InDiv);
	
	float Modulus();
	int Quotient();
	float PercentRemainder();

private:

	float Modulus_;
	float PercentRemainder_;
	int Quotient_;
};

class ModuloC
{

public:


		static ModuloFloatS ModuloFloat(float InTotal, float InDiv);

		static int Quotient(float InTotal, float InDiv);

};
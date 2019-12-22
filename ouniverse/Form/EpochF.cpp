//Copyright 2015-2019, All Rights Reserved.

#include "Form/EpochF.h"
#include "Form/EpochA.h"

#include "System/FormTypes.h"
#include "Interface/Json.h"


int EpochF::Type()
{
	return FormTypesC::Types::Epoch;
}

UEpochA* EpochF::CreateActual()
{
	return UEpochA::Create(this);
}

EpochF::EpochF()
{

}

DataD* EpochF::Create(JsonS& InJ)
{ 
	DataD* Obj = new EpochF();
	Obj->Setup(InJ);
	return Obj;
}

void EpochF::Demarshal()
{
	DataD::Demarshal();
}

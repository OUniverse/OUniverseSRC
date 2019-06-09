//Copyright 2015-2019, All Rights Reserved.

#include "System/FormLib.h"

#include "Form/FormF.h"
#include "Form/RefF.h"

#include "System/Payload.h"

FormLibC::FormLibC()
{
	Num_ = 0;

	FactoryArray.Init(Types::TYPES_MAX, NULL);
	FactoryArray[Types::Form]	= FormF::Create;
	//FactoryArray[Types::Ref]	= RefF::Create;

}


void FormLibC::AddList(JsonS* InJ)
{

	//int Type;

	//int L = InJ->Len();

	//for (int i = 0; i < L; i++)
	//{
	//	JsonS J = JTotal[i];
	//	Type = J.Int("t");
	//	FormF* Form = FactoryArray[Type](J);
	//	PreLib_.Add(Form->UID(), Form);
	//}
}

FormF* FormLibC::operator[](U32 InValue)
{
	return PreLib_[InValue];
}

void FormLibC::LinkBoost(AtlasLibC* InAtlasLib)
{

}

void FormLibC::LinkExtra(AtlasLibC* InAtlasLib)
{

}
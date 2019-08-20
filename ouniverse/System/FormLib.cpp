//Copyright 2015-2019, All Rights Reserved.

#include "System/FormLib.h"

#include "Form/FormF.h"
#include "Form/RefF.h"
#include "Form/ObjectF.h"
#include "Form/ActorF.h"
#include "Form/EpochF.h"
#include "Form/ActraF.h"

#include "System/Payload.h"

#include "System/Log.h"


const char* FormLibC::K_UID = "u";
const char* FormLibC::K_TYPE = "t";


FormLibC::FormLibC(AtlasC* InOwningAtlas)
{
	Len_ = 0;
	OwningAtlas = InOwningAtlas;

	FactoryArray.Init(Types::TYPES_MAX, NULL);
	FactoryArray[Types::Form]	= FormF::Create;
	FactoryArray[Types::Ref]	= RefF::Create;
	FactoryArray[Types::Object]	= ObjectF::Create;
	FactoryArray[Types::Actor]	= ActorF::Create;
	FactoryArray[Types::Epoch]	= EpochF::Create;
	FactoryArray[Types::Actra]	= ActraF::Create;

}


int FormLibC::Len()
{
	return Len_;
}

void FormLibC::AddList(JsonS* InJ)
{

	int L = InJ->Len();


	for (int i = 0; i < L; i++)
	{
		JsonS NewForm = InJ->At(i);
		int Type = NewForm.Int(FormLibC::K_TYPE);
		FormF* Form = FactoryArray[Type](NewForm);
		Add(Form);
	}
}


void FormLibC::Add(FormF* NewForm)
{
	Len_++;
	LOG(54439, NewForm->UID(), "Adding Form: $V$")
	Lib_.Add(NewForm->UID(), NewForm);
}

FormF* FormLibC::operator[](U32 InValue)
{
	return Lib_[InValue];
}

void FormLibC::LinkBoost(AtlasLibC* InAtlasLib)
{

}

void FormLibC::LinkExtra(AtlasLibC* InAtlasLib)
{

}

void FormLibC::Query(FormQueryS* InQuery)
{
	FormWrapS FormWrap;

	for (int i = 0; i < Len(); i++)
	{
		FormWrap = FormWrapS(OwningAtlas, Lib_.At(i));
		InQuery->Scan(FormWrap);
	}

}
//Copyright 2015-2019, All Rights Reserved.

#include "System/FormLib.h"
#include "System/FormTypes.h"

#include "Key/GlobalK.h"

#include "Form/FormF.h"
#include "Form/RefF.h"
#include "Form/ObjectF.h"
#include "Form/ActorF.h"
#include "Form/EpochF.h"
#include "Form/ActraF.h"

#include "System/Payload.h"

#include "System/Log.h"


FormLibC::FormLibC(AtlasC* InOwningAtlas)
{
	Len_ = 0;
	OwningAtlas = InOwningAtlas;

	FactoryArray.Init(FormTypesC::Types::TYPES_MAX, NULL);
	FactoryArray[FormTypesC::Types::Form]	= FormF::Create;
	FactoryArray[FormTypesC::Types::Ref]	= RefF::Create;
	FactoryArray[FormTypesC::Types::Object]	= ObjectF::Create;
	FactoryArray[FormTypesC::Types::Actor]	= ActorF::Create;
	FactoryArray[FormTypesC::Types::Epoch]	= EpochF::Create;
	FactoryArray[FormTypesC::Types::Actra]	= ActraF::Create;

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
		int Type = NewForm.Int(GlobalK::Type);
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

FormF* FormLibC::Get(U32 InValue)
{
	return Lib_[InValue];
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

FormWrapS FormLibC::GetFormWrap(U32 InForm)
{
	return FormWrapS(OwningAtlas, Lib_[InForm]);
}


StringC FormLibC::Serialize()
{
	return ToJson().Serialize();
}

JsonS FormLibC::ToJson()
{
	ArrayC<JsonS> JArr;

	JsonS J = JsonS();

	for (int i = 0; i < Len(); i++)
	{
		JArr.Add(Lib_.At(i)->ToJson());
	}

	J.Array(JArr);

	return J;
}
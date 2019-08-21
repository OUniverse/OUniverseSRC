//Copyright 2015-2019, All Rights Reserved.

#include "System/AmendmentLib.h"

#include "System/Amendment.h"

#include "System/FormWrap.h"

#include "System/Log.h"


const char* AmendmentLibC::K_UID = "u";
const char* AmendmentLibC::K_TYPE = "t";


AmendmentLibC::AmendmentLibC(AtlasC* InOwningAtlas, AtlasLibC* InAtlasLib)
{
	Len_ = 0;
	AtlasLib_ = InAtlasLib;
	OwningAtlas_ = InOwningAtlas;
}

int AmendmentLibC::Len()
{
	return Len_;
}

void AmendmentLibC::AddList(JsonS* InJ)
{

	int L = InJ->Len();


	for (int i = 0; i < L; i++)
	{
		JsonS AmendmentJ = InJ->At(i);
		AmendmentC* Amendment = new AmendmentC(AmendmentJ);
		Add(Amendment);
	}
}


void AmendmentLibC::Add(AmendmentC* InAmendment)
{
	Len_++;
	Lib_.Add(InAmendment->UID(), InAmendment);
}

AmendmentC* AmendmentLibC::Get(StringC InValue)
{
	return Lib_[InValue];
}

AmendmentC* AmendmentLibC::operator[](StringC InValue)
{
	return Lib_[InValue];
}

void AmendmentLibC::Query(FormQueryS* InQuery)
{
	FormWrapS FormWrap;

	for (int i = 0; i < Len(); i++)
	{
		//FormWrap = FormWrapS(OwningAtlas_, Lib_.At(i));
		//InQuery->Scan(FormWrap);
	}

}

FormWrapS AmendmentLibC::GetFormWrap(U32 InForm)
{
	return FormWrapS();
	//return FormWrapS(OwningAtlas_, Lib_[InForm]);
}

JsonS AmendmentLibC::ToJson()
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
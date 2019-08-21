//Copyright 2015-2019, All Rights Reserved.

#include "System/RevisionLib.h"

#include "System/Revision.h"

#include "System/FormWrap.h"

#include "System/Log.h"


RevisionLibC::RevisionLibC(AtlasC* InOwningAtlas, AtlasLibC* InAtlasLib)
{
	Len_ = 0;
	AtlasLib_ = InAtlasLib;
	OwningAtlas_ = InOwningAtlas;
}

int RevisionLibC::Len()
{
	return Len_;
}

void RevisionLibC::AddList(JsonS* InJ)
{

	int L = InJ->Len();


	for (int i = 0; i < L; i++)
	{
		JsonS RevisionJ = InJ->At(i);
		RevisionC* Revision = new RevisionC(RevisionJ);
		Add(Revision);
	}
}


void RevisionLibC::Add(RevisionC* InRevision)
{
	Len_++;
	Lib_.Add(InRevision->UID(), InRevision);
}

RevisionC* RevisionLibC::Get(StringC InValue)
{
	return Lib_[InValue];
}

RevisionC* RevisionLibC::operator[](StringC InValue)
{
	return Lib_[InValue];
}

void RevisionLibC::Query(FormQueryS* InQuery)
{
	FormWrapS FormWrap;

	for (int i = 0; i < Len(); i++)
	{
		//FormWrap = FormWrapS(OwningAtlas_, Lib_.At(i));
		//InQuery->Scan(FormWrap);
	}

}

FormWrapS RevisionLibC::GetFormWrap(U32 InForm)
{
	return FormWrapS();
	//return FormWrapS(OwningAtlas_, Lib_[InForm]);
}

JsonS RevisionLibC::ToJson()
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
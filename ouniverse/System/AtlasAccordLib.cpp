//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasAccordLib.h"
#include "System/AtlasAccord.h"


AtlasAccordLibC::AtlasAccordLibC()
{
	Len_ = 0;
}

AtlasAccordLibC::~AtlasAccordLibC()
{
//DELETECHECK
	for (int i = 0; i < Len(); i++)
	{
		delete Lib_[i];
	}
}

int AtlasAccordLibC::Len()
{
	return Len_;
}

void AtlasAccordLibC::AddList(JsonS* InJ)
{

	int L = InJ->Len();


	for (int i = 0; i < L; i++)
	{
		AtlasAccordC* Accord = new AtlasAccordC(InJ->At(i).ToAtlasUID());
		Add(Accord);
	}
}


void AtlasAccordLibC::Add(AtlasAccordC* InAccord)
{
	Len_++;
	Lib_.Add(InAccord);
}

AtlasAccordC* AtlasAccordLibC::Get(int Ix)
{
	return Lib_[Ix];
}

StringC AtlasAccordLibC::Serialize()
{
	return ToJson().Serialize();
}

JsonS AtlasAccordLibC::ToJson()
{
	ArrayC<JsonS> JArr;


	for (int i = 0; i < Len(); i++)
	{
		JArr.Add(JsonS(Lib_[i]->UID()));
	}
	
	JsonS J = JsonS();
	J.Array(JArr);

	return J;
}


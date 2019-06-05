//Copyright 2015-2019, All Rights Reserved.

#include "Interface/StackF.h"
#include "Form/FactoryF.h"
#include "Form/FormF.h"

#include "Interface/Int.h"
#include "Interface/Json.h"

StackF::StackF()
{
	
}

StackF::StackF(FactoryF* InFactory, int Start, long long Count, StringC InLine)
{
	int FType = 0;
	int FUID = 0;

	Writer_ = new WriterS(Count);

	for (int i = 0; i < Count; i++)
	{
		InLine.SubString(0, 5).BeInt(FType);
		InLine.SubString(5, 10).BeInt(FUID);

		Map_.Add(FUID, InFactory->FAC[FType]());
		Writer_->Add(FUID, InLine.SubString(11, -1));
	}
}

void StackF::Bloom()
{
	int Count = Writer_->TempList.Len();

	for (int i = 0; i < Count; i++)
	{
		JsonS Serialized = JsonS(Writer_->TempList[i].Data);
		Map_[Writer_->TempList[i].UID].Marshal(&Serialized);
	}

	delete Writer_;	
}


bool StackF::Valid()
{
	return true;
}


StackF::WriterS::WriterS(int Length)
{
	Cursor = 0;
	TempList.Init(Length, TempS());
}

void StackF::WriterS::Add(int UID, StringC Data)
{
	TempList[Cursor].Set(UID, Data);
	Cursor++;
}

StackF::WriterS::TempS::TempS()
{
	UID = 0;
	Data = "";
}

void StackF::WriterS::TempS::Set(int InUID, StringC InData)
{
	UID = InUID;
	Data = InData;
}
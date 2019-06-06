//Copyright 2015-2019, All Rights Reserved.

#include "System/Scribe.h"
#include "Interface/File.h"
#include "Interface/Dir.h"


const char* ScribeC::FILE_NAME = "scribe.html";

namespace GlobalSingleton
{
	ScribeC Scribe;
}

ScribeC* ScribeC::Get()
{
	return &GlobalSingleton::Scribe;
}

ScribeC* ScribeC::Create(DirS* InDirLogs)
{
	GlobalSingleton::Scribe = *(new ScribeC(InDirLogs));
	return &GlobalSingleton::Scribe;
}

ScribeC::ScribeC() {}

ScribeC::ScribeC(DirS* InDirLogs)
{
	Cursor = 0;
	Count = 0;
	DirLogs = InDirLogs;

	FileC LogFile = FileC(DirLogs->Get()/ScribeC::FILE_NAME);
	LogFile.Empty();
}


void ScribeC::Print()
{
	StringC LogAmendment = "";

	for (int i = Cursor; i < Count; i++)
	{
		LogAmendment += EntryArray[i]->Output().NewLine();
		Cursor++;
	}

	FileC LogFile = FileC(DirLogs->Get() / ScribeC::FILE_NAME);
	LogFile.Append(LogAmendment);
}

void ScribeC::Stamp(ScribeC::Entry* Entry)
{
	Count++;
	EntryArray += Entry;
}

StringC ScribeC::Entry::Brass()
{
	return StringC(Code32_);
}









ScribeC::Entry::Entry(int Code32)
{
	Code32_ = Code32;
	//Set Timestamp;
}

StringC ScribeC::Entry::Output()
{
	return Brass();
}

void ScribeC::Write(int Code32, Void Nothing)
{
	Stamp(new ScribeC::Entry(Code32));
}












ScribeC::EntryBool::EntryBool(int Code32, bool InAux) : ScribeC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC ScribeC::EntryBool::Output()
{
	return Brass() & StringC(Aux_);
}

void ScribeC::Write(int Code32, bool InAux)
{
	Stamp(new ScribeC::EntryBool(Code32,InAux));
}








ScribeC::EntryString::EntryString(int Code32, StringC InAux) : ScribeC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC ScribeC::EntryString::Output()
{
	return Brass() & StringC(Aux_);
}

void ScribeC::Write(int Code32, const char* InAux)
{
	Write(Code32, StringC(InAux));
}

void ScribeC::Write(int Code32, StringC InAux)
{
	Stamp(new ScribeC::EntryString(Code32, InAux));
}












ScribeC::EntryFloat::EntryFloat(int Code32, float InAux) : ScribeC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC ScribeC::EntryFloat::Output()
{
	return Brass() & StringC(Aux_);
}

void ScribeC::Write(int Code32, float InAux)
{
	Stamp(new ScribeC::EntryFloat(Code32, InAux));
}







ScribeC::EntryInt::EntryInt(int Code32, int InAux) : ScribeC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC ScribeC::EntryInt::Output()
{
	return Brass() & StringC(Aux_);
}

void ScribeC::Write(int Code32, int InAux)
{
	Stamp(new ScribeC::EntryInt(Code32, InAux));
}







ScribeC::EntryU64::EntryU64(int Code32, U64 InAux) : ScribeC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC ScribeC::EntryU64::Output()
{
	return Brass() & StringC(Aux_);
}

void ScribeC::Write(int Code32, U64 InAux)
{
	Stamp(new ScribeC::EntryU64(Code32, InAux));
}
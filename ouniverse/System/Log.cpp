//Copyright 2015-2019, All Rights Reserved.

#include "System/Log.h"
#include "Interface/File.h"
#include "Interface/Dir.h"


const char* LogC::FILE_NAME = "log.txt";

namespace GlobalSingleton
{
	LogC Log;
}

LogC* LogC::Get()
{
	return &GlobalSingleton::Log;
}

LogC* LogC::Create(DirS* InDirLogs)
{
	GlobalSingleton::Log = *(new LogC(InDirLogs));
	return &GlobalSingleton::Log;
}

LogC::LogC() {}

LogC::LogC(DirS* InDirLogs)
{
	Cursor = 0;
	Count = 0;
	DirLogs = InDirLogs;

	FileC LogFile = FileC(DirLogs->Get()/LogC::FILE_NAME);
	LogFile.Empty();
}


void LogC::Print()
{
	StringC LogAmendment = "";

	for (int i = Cursor; i < Count; i++)
	{
		LogAmendment += EntryArray[i]->Output().NewLine();
		Cursor++;
	}

	FileC LogFile = FileC(DirLogs->Get() / LogC::FILE_NAME);
	LogFile.Append(LogAmendment);
}

void LogC::Stamp(LogC::Entry* Entry)
{
	Count++;
	EntryArray += Entry;
}

StringC LogC::Entry::Brass()
{
	return StringC(Code32_);
}









LogC::Entry::Entry(int Code32)
{
	Code32_ = Code32;
	//Set Timestamp;
}

StringC LogC::Entry::Output()
{
	return Brass();
}

void LogC::Write(int Code32, Void Nothing)
{
	Stamp(new LogC::Entry(Code32));
}












LogC::EntryBool::EntryBool(int Code32, bool InAux) : LogC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC LogC::EntryBool::Output()
{
	return Brass() & StringC(Aux_);
}

void LogC::Write(int Code32, bool InAux)
{
	Stamp(new LogC::EntryBool(Code32,InAux));
}








LogC::EntryString::EntryString(int Code32, StringC InAux) : LogC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC LogC::EntryString::Output()
{
	return Brass() & StringC(Aux_);
}

void LogC::Write(int Code32, const char* InAux)
{
	Write(Code32, StringC(InAux));
}

void LogC::Write(int Code32, StringC InAux)
{
	Stamp(new LogC::EntryString(Code32, InAux));
}












LogC::EntryFloat::EntryFloat(int Code32, float InAux) : LogC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC LogC::EntryFloat::Output()
{
	return Brass() & StringC(Aux_);
}

void LogC::Write(int Code32, float InAux)
{
	Stamp(new LogC::EntryFloat(Code32, InAux));
}







LogC::EntryInt::EntryInt(int Code32, int InAux) : LogC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC LogC::EntryInt::Output()
{
	return Brass() & StringC(Aux_);
}

void LogC::Write(int Code32, int InAux)
{
	Stamp(new LogC::EntryInt(Code32, InAux));
}







LogC::EntryU64::EntryU64(int Code32, U64 InAux) : LogC::Entry(Code32)
{
	Aux_ = InAux;
}

StringC LogC::EntryU64::Output()
{
	return Brass() & StringC(Aux_);
}

void LogC::Write(int Code32, U64 InAux)
{
	Stamp(new LogC::EntryU64(Code32, InAux));
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/Log.h"

#include "Misc/DateTime.h"


#include "Min/DebugM.h"

const char* LogC::FILE_NAME = "log.txt";
const char* LogC::Delimiter = "—";

namespace GlobalSingleton
{
	LogC Log;
}

LogC* LogC::Get()
{
	return &GlobalSingleton::Log;
}

LogC* LogC::Create(FileC InFile)
{
	GlobalSingleton::Log = *(new LogC(InFile));
	return &GlobalSingleton::Log;
}

LogC::LogC() {}

LogC::LogC(FileC InFile)
{
	Cursor = 0;
	Count = 0;
	LogFile = InFile;
	
	LogFile.Doc().Empty();
}


void LogC::Print()
{
	StringC LogAmendment = "";

	for (int i = Cursor; i < Count; i++)
	{
		LogAmendment += EntryArray[i]->Output().NewLine();
		Cursor++;
	}

	LogFile.Doc().Append(LogAmendment);
}

void LogC::Stamp(LogC::Entry* Entry)
{
	Count++;
	EntryArray += Entry;
}

StringC LogC::Entry::Brass()
{
	return StringC(Time_) + StringC(LogC::Delimiter) + StringC(Code32_);
}









LogC::Entry::Entry(int Code32)
{
	Code32_ = Code32;
	Time_ = FDateTime::Now().GetTicks();
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
	return Brass() + StringC(LogC::Delimiter) + StringC(Aux_);
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
	return Brass() + StringC(LogC::Delimiter) + StringC(Aux_);
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
	return Brass() + StringC(LogC::Delimiter) + StringC(Aux_);
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
	return Brass() + StringC(LogC::Delimiter) + StringC(Aux_);
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
	return Brass() + StringC(LogC::Delimiter) + StringC(Aux_);
}

void LogC::Write(int Code32, U64 InAux)
{
	Stamp(new LogC::EntryU64(Code32, InAux));
}




void LogC::Write(int Code32, U32 InAux)
{
	Stamp(new LogC::EntryInt(Code32, InAux.Ref()));
}
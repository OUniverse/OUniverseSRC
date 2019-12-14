//Copyright 2015-2019, All Rights Reserved.

#include "System/Logger.h"
#include <fstream>
#include <string>

#include "Min/DebugM.h"

namespace GlobalSingleton
{
	LoggerC* Logger;
}

LoggerEntryC::LoggerEntryC(int InIndex)
{
	Index_ = InIndex;
}

LoggerOutputS LoggerEntryC::Output()
{
	return LoggerOutputS();
}


LoggerEntryC* LoggerEntryC::Nest(LoggerEntryC* InEntry)
{
	Nested_.Add(InEntry);
	return InEntry;
}

LoggerEntryC* LoggerEntryC::Mail()
{
	GlobalSingleton::Logger->Add(this);
	return this;
}

int LoggerEntryC::Index()
{
	return Index_;
}

FText LoggerEntryC::GetCategory(int Index)
{
	return GlobalSingleton::Logger->GetCategory(Index);
}



LoggerEntryC* LoggerEntryC::W(StringC InText, int8_t InCat, int8_t InFlag)
{
	return new LoggerEntryTextC(GlobalSingleton::Logger->Increment(),InText, InCat, InFlag);
}

LoggerEntryC* LoggerEntryC::W(const char* InText, int8_t InCat, int8_t InFlag)
{
	return new LoggerEntryTextC(GlobalSingleton::Logger->Increment(),InText, InCat, InFlag);
}

LoggerEntryC* LoggerEntryC::W(int InHash)
{
	return new LoggerEntryHashC(GlobalSingleton::Logger->Increment(),InHash);
}

LoggerEntryC* LoggerEntryC::W(int InHash, StringC InAux)
{
	return new LoggerEntryStringC(GlobalSingleton::Logger->Increment(),InHash, InAux);
}

LoggerEntryC* LoggerEntryC::W(int InHash, int InAux)
{
	return new LoggerEntryIntC(GlobalSingleton::Logger->Increment(),InHash, InAux);
}

LoggerEntryC* LoggerEntryC::W(int InHash, float InAux)
{
	return new LoggerEntryFloatC(GlobalSingleton::Logger->Increment(),InHash, InAux);
}




LoggerEntryTextC::LoggerEntryTextC(int InIndex, StringC InText, int8_t InCat, int8_t InFlag) : LoggerEntryC(InIndex)
{
	Text_ = InText;
	Cat_ = InCat;
	Flag_ = InFlag;
}

LoggerOutputS  LoggerEntryTextC::Output()
{
	return LoggerOutputS(Text_,Cat_,Flag_);
}



LoggerEntryHashC::LoggerEntryHashC(int InIndex, uint16_t InHash) : LoggerEntryC(InIndex)
{
	Hash_ = InHash;
	//Time_ = FDateTime::Now().GetTicks();
}

LoggerOutputS LoggerEntryHashC::Output()
{	
	LoggerLegendS* Legend;

	if (GlobalSingleton::Logger->Legend_.TryPointer(Hash_, Legend))
	{
		return LoggerOutputS(Legend->Text, Legend->Flag, Legend->Cat);
	}

	return LoggerOutputS();
}





LoggerEntryBoolC::LoggerEntryBoolC(int InIndex, uint16_t InHash, bool InAux) : LoggerEntryHashC(InIndex,InHash)
{
	Aux_ = InAux;
}

LoggerOutputS LoggerEntryBoolC::Output()
{
	LoggerLegendS* Legend;

	if (GlobalSingleton::Logger->Legend_.TryPointer(Hash_, Legend))
	{
		StringC Text = Legend->Text.FindAndReplace(LoggerC::LogVar1, Aux_);
		return LoggerOutputS(Text, Legend->Flag, Legend->Cat);
	}

	return LoggerOutputS();
}




LoggerEntryStringC::LoggerEntryStringC(int InIndex, uint16_t InHash, StringC InAux) : LoggerEntryHashC(InIndex, InHash)
{
	Aux_ = InAux;
}

LoggerOutputS LoggerEntryStringC::Output()
{
	LoggerLegendS* Legend;

	if (GlobalSingleton::Logger->Legend_.TryPointer(Hash_, Legend))
	{
		StringC Text = Legend->Text.FindAndReplace(LoggerC::LogVar1, Aux_);
		return LoggerOutputS(Text, Legend->Flag, Legend->Cat);
	}

	return LoggerOutputS();
}





LoggerEntryIntC::LoggerEntryIntC(int InIndex, uint16_t InHash, int InAux) : LoggerEntryHashC(InIndex, InHash)
{
	Aux_ = InAux;
}

LoggerOutputS LoggerEntryIntC::Output()
{
	LoggerLegendS* Legend;

	if (GlobalSingleton::Logger->Legend_.TryPointer(Hash_, Legend))
	{
		StringC Text = Legend->Text.FindAndReplace(LoggerC::LogVar1, Aux_);
		return LoggerOutputS(Text, Legend->Flag, Legend->Cat);
	}

	return LoggerOutputS();
}



LoggerEntryFloatC::LoggerEntryFloatC(int InIndex, uint16_t InHash, float InAux) : LoggerEntryHashC(InIndex, InHash)
{
	Aux_ = InAux;
}

LoggerOutputS LoggerEntryFloatC::Output()
{
	LoggerLegendS* Legend;

	if (GlobalSingleton::Logger->Legend_.TryPointer(Hash_, Legend))
	{
		StringC Text = Legend->Text.FindAndReplace(LoggerC::LogVar1, Aux_);
		return LoggerOutputS(Text,Legend->Flag,Legend->Cat);
	}
	
	return LoggerOutputS();
}






LoggerC* LoggerC::Create(FileC InLegendFile, FileC InOutputFile)
{
	LoggerC* Neu = new LoggerC(InLegendFile, InOutputFile);
	GlobalSingleton::Logger = Neu;
	return Neu;
}

LoggerC* LoggerC::Get()
{
	return GlobalSingleton::Logger;
}

int LoggerC::Num()
{
	return Entries_.Len();
}

LoggerC::LoggerC(FileC InLegendFile, FileC InOutputFile)
{
	Inc_ = -1;

	OutputFile_ = InOutputFile;

	std::string LineSS;
	std::ifstream FileSS;

	FileSS.open(InLegendFile.ToString().ToChar());

	int C1; 
	int C2;
	int C3;
	int Hash;
	int Cat;
	int Flag;
	
	StringC Parser;

	LoggerLegendS Legend;

	std::getline(FileSS, LineSS);

	ArrayC<StringC>  CatArr = StringC(LineSS).Split(',');

	int L = CatArr.Len();

	for (int i = 0; i < L; i++)
	{
		Cats_.Add(CatArr[i].ToFText());
	}

	while (std::getline(FileSS, LineSS))
	{
		C1 = LineSS.find(",", 0);
		C2 = LineSS.find(",", C1 + 1);
		C3 = LineSS.find(",", C2 + 1);
		
		Parser = StringC(LineSS.substr(0, C1));

		if (Parser.BeInt(Hash))
		{
			
			Parser = StringC(LineSS.substr(C1+1, (C2-C1)-1));
			
			if (Parser.BeInt(Flag))
			{
				Parser = StringC(LineSS.substr(C2 + 1, (C3 - C2)-1));

				if (Parser.BeInt(Cat))
				{
					Parser = StringC(LineSS.substr(C3 + 1, std::string::npos));
					Legend_.Add(Hash,LoggerLegendS(Parser,Flag,Cat));

				}
			}
		}
	}                                        
}
                                    
LoggerEntryC* LoggerC::GetEntry(uint16_t Index)
{
	return Entries_[Index];
}
LoggerEntryC* LoggerC::Add(LoggerEntryC* InEntry)
{
	Entries_.Add(InEntry);
	return InEntry;
}

int LoggerC::Increment()
{
	Inc_++;
	return Inc_;
}

FText LoggerC::GetCategory(int Index)
{
	return Cats_[Index];
}
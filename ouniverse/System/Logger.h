//Copyright 2015-2019, All Rights Reserved.

/**

## Log

Logging class, primarily intended to be created once by the boot process and used as a singleton.
> Here it's created once at startup by the boot script but can be instanced if needed.

**Creator:** UBoot
**Holder:** Major

The log's symbol conversions are stored in a google drive spread sheet:

https://docs.google.com/spreadsheets/d/1Lf-CjJtFdgNLNyTyuD-akRAJHqLrEujYSaIUBhljuqs/edit#gid=0

 */


#pragma once

#include "CoreMinimal.h"
#include "Interface/String.h"
#include "Interface/Array.h"
#include "Interface/Map.h"
#include "Interface/Url.h"


#if !defined LOGGER
#define LOGGER(text,fn) fn;
#endif

struct OUNIVERSE_API LoggerLegendS
{
	StringC Text;
	int8_t Cat;
	int8_t Flag;

	LoggerLegendS() {};

	LoggerLegendS(StringC InText, int8_t InCat, int8_t InFlag)
	{
		Text = InText;
		Cat = InCat;
		Flag = InFlag;
	}
};

struct OUNIVERSE_API LoggerOutputS
{
	StringC Text;
	int8_t Cat;
	int8_t Flag;


	LoggerOutputS() {};

	LoggerOutputS(StringC InText, int8_t InCat, int8_t InFlag)
	{
		Text = InText;
		Cat = InCat;
		Flag = InFlag;
	}

	LoggerOutputS(LoggerLegendS* InLegend)
	{
		Text = InLegend->Text;
		Cat = InLegend->Cat;
		Flag = InLegend->Flag;
	}
};


class OUNIVERSE_API LoggerEntryC
{

public:

	LoggerEntryC(int InIndex);
	virtual ~LoggerEntryC() {};

	virtual LoggerOutputS Output();

	LoggerEntryC* Mail();

	FText GetCategory(int Index);

	static LoggerEntryC* W(StringC InText, int8_t InCat, int8_t InFlag);
	static LoggerEntryC* W(const char* InText, int8_t InCat, int8_t InFlag);

	static LoggerEntryC* W(int InHash);
	static LoggerEntryC* W(int InHash, StringC InAux);
	static LoggerEntryC* W(int InHash, int InAux);
	static LoggerEntryC* W(int InHash, float InAux);

	virtual bool IsHash() { return false; };

	int Index();

private:

	ArrayC<LoggerEntryC*> Nested_;

	LoggerEntryC* Nest(LoggerEntryC* InEntry);

	int Index_;

};

class OUNIVERSE_API LoggerEntryTextC : public LoggerEntryC
{

public:

	LoggerEntryTextC(int InIndex, StringC InText, int8_t InCat, int8_t InFlag);

	virtual LoggerOutputS Output();

private:

	StringC Text_;
	int8_t Flag_;
	int8_t Cat_;
};

class OUNIVERSE_API LoggerEntryHashC : public LoggerEntryC
{

public:

	LoggerEntryHashC(int InIndex, uint16_t InHash);

	virtual LoggerOutputS Output();

	bool IsHash() override { return true; };

protected:

	uint16_t Hash_;
};


class OUNIVERSE_API LoggerEntryBoolC : public LoggerEntryHashC
{

public:

	LoggerEntryBoolC(int InIndex, uint16_t InHash, bool InAux);

	virtual LoggerOutputS Output();

private:

	bool Aux_;

};

class OUNIVERSE_API LoggerEntryStringC : public LoggerEntryHashC
{

public:

	LoggerEntryStringC(int InIndex, uint16_t InHash, StringC InString);

	virtual LoggerOutputS Output();

private:

	StringC Aux_;

};


class OUNIVERSE_API LoggerEntryIntC : public LoggerEntryHashC
{

public:

	LoggerEntryIntC(int InIndex, uint16_t InHash, int InAux);

	virtual LoggerOutputS Output();

private:

	int Aux_;

};

class OUNIVERSE_API LoggerEntryFloatC : public LoggerEntryHashC
{

public:

	LoggerEntryFloatC(int InIndex, uint16_t InHash, float InAux);

	virtual LoggerOutputS Output();

private:

	float Aux_;

};

class OUNIVERSE_API LoggerC
{

public:
	
	static constexpr const char* LogVar1 = "{0}";

	enum Flag : int8_t
	{
		Fatal,
		Error,
		Soft,
		Reject,
		Notice,
		Trace,
		Debug,
	};

	enum Cat : int8_t
	{
		Boot,
		Data,		
	};

	enum Verb : int8_t
	{
		Low,
		Medium,
		High,
	};

	static LoggerC* Create(FileC InLegendFile, FileC InOutputFile);

	static LoggerC* Get();

	int Num();

	LoggerEntryC* Add(LoggerEntryC* InEntry);

private:

	FileC OutputFile_;

	LoggerC(FileC InLegendFile, FileC InOutput);

public:

	int Increment();

	int Inc_;

	LoggerEntryC* GetEntry(uint16_t Index);

	ArrayC<LoggerEntryC*> Entries_;
	
	MapC<uint16_t, LoggerLegendS> Legend_;

	ArrayC<FText> Cats_;

	FText GetCategory(int Index);

};
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
#include "Interface/Void.h"

#define LOG(Code32,Aux,Summary) LogC::Get()->Write(Code32,Aux);

#define LOGP LogC::Get()->Print();


class BootC;

extern struct DirS;


class OUNIVERSE_API LogC
{

	static const char* FILE_NAME;

	friend BootC;

private:
		
	LogC(DirS* InDirLogs);

	static LogC* Create(DirS* InDirLogs);

	int Cursor;
	int Count;
	DirS* DirLogs;
	
	struct Entry
	{

	public:

		Entry(int InCode32);

		virtual StringC Output();

		StringC Brass();
	
		virtual ~Entry() {};

	private:
		
		int Code32_;
		U64 Time_;


	};


	struct EntryBool : public Entry
	{
		EntryBool(int InCode32, bool b);

		virtual StringC Output() override;

	private:

		bool Aux_;
	};


	struct EntryString : public Entry
	{
		EntryString(int InCode32, StringC s);

		virtual StringC Output() override;

	private:

		StringC Aux_;
	};


	struct EntryFloat : public Entry
	{
		EntryFloat(int InCode32, float f);

		virtual StringC Output() override;

	private:

		float Aux_;
	};


	struct EntryInt : public Entry
	{
		EntryInt(int InCode32, int i);

		virtual StringC Output() override;

	private:

		int Aux_;
	};


	struct EntryU64 : public Entry
	{
		EntryU64(int InCode32, U64 u64);

		virtual StringC Output() override;

	private:

		U64 Aux_;
	};


	ArrayC<LogC::Entry*> EntryArray;

public:

		LogC();

		static LogC* Get();

		void Stamp(LogC::Entry* Entry);
		
		void Write(int Code32, Void Nothing);
		void Write(int Code32, const char* InAux);
		void Write(int Code32, bool InAux);
		void Write(int Code32, StringC InAux);
		void Write(int Code32, int InAux);
		void Write(int Code32, float InAux);
		void Write(int Code32, U64 InAux);
		void Write(int Code32, U32 InAux);

		void Print();

};
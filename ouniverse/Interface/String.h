//Copyright 2015-2019, All Rights Reserved.

/**

## String

**Class:** StringC

Generic string implementation.
> Wrapper around a std::string with some custom functionality.

*/

#pragma once

#include "CoreMinimal.h"
#include "Interface/Array.h"

#include "Interface/Int.h"

#include <string>

class StringC
{

public:

	StringC();

	StringC(const char* inText);
	
	StringC(std::string inText);

	StringC(FString Text);

	StringC(float In);
	
	StringC(int In);

	StringC(bool In);

	const char* ToChar();

	const char* ToPath();
	std::string ToStd();

	std::string ToStd() const;

	FString ToFString();

	bool operator<(const StringC& l) const;

	bool operator!=(StringC In);

	bool operator==(StringC In);

	StringC operator+(StringC In);

	StringC operator+(int In);
	
	StringC operator+(std::string In);

	StringC operator+(const char* In);

	StringC& operator+=(StringC In);

	StringC& operator+=(int In);

	StringC& operator+=(std::string In);

	StringC& operator+=(const char* In);
	
	StringC& operator/(const char* In);

	StringC& operator/(StringC& In);

	StringC operator[](int Index);

	bool BeBool(bool& Out);

	bool BeFullBool(bool& Out);

	bool BeFloat(float& Out);

	bool BeInt(int& Out);

	bool BeInt(UInt8& Out);

	bool BeInt(UInt16& Out);

	bool BeInt(UInt32& Out);

	bool BeInt(UInt64& Out);

	bool BeInt(long long& Out);

	int Len();

	StringC& Sanitize();

	StringC& NewLine();

	StringC& RemoveLastChar();
	StringC SubString(int Index1, int Index2);

	StringC Trim(int From);

	StringC Trim(int From, int To);

	StringC TrimExtension();

	int FindLast(const char* S);

	static int NPOS();

	ArrayC<StringC> Delimit(StringC S, char D);


	UInt8 ToU8ZeroFail();

	UInt16 ToU16ZeroFail();


private:

	std::string s;

public:

	FORCEINLINE static std::string FStringToString(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static const char* FStringToChar(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static FString StringToFString(std::string Text) { return UTF8_TO_TCHAR(Text.c_str()); };

	FORCEINLINE static const char* StringToChar(std::string Text) { return Text.c_str(); };

};


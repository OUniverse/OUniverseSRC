//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
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

	std::string ToStd();

	std::string ToStd() const;

	FString ToFString();

	bool operator<(const StringC& l) const;

	bool operator!=(StringC In);

	bool operator==(StringC In);

	StringC& operator+(StringC In);

	StringC& operator+(int In);
	
	StringC& operator+(std::string In);

	StringC& operator+(const char* In);

	StringC& operator+=(StringC In);

	StringC& operator+=(int In);

	StringC& operator+=(std::string In);

	StringC& operator+=(const char* In);
	
	StringC& operator/(const char* In);

	StringC& operator/(StringC& In);

	bool BeBool(bool& Out);

	bool BeFullBool(bool& Out);

	bool BeFloat(float& Out);

	bool BeInt(int& Out);

	StringC& Sanitize();

	StringC& NewLine();

private:

	std::string s;

public:

	FORCEINLINE static std::string FStringToString(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static const char* FStringToChar(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static FString StringToFString(std::string Text) { return UTF8_TO_TCHAR(Text.c_str()); };

	FORCEINLINE static const char* StringToChar(std::string Text) { return Text.c_str(); };

};


//Copyright 2015-2019, All Rights Reserved.

#include "CoreMinimal.h"
#include <string>

class StringC
{
public:

	FORCEINLINE static std::string FStringToString(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static const char* FStringToChar(FString Text) { return TCHAR_TO_UTF8(*Text); };

	FORCEINLINE static FString StringToFString(std::string Text) { return UTF8_TO_TCHAR(Text.c_str()); };

	FORCEINLINE static const char* StringToChar(std::string Text) { return Text.c_str(); };

};
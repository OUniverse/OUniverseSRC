//Copyright 2015-2019, All Rights Reserved.

#include "CoreMinimal.h"
#include <sstream>

class Conv
{
public:

	static bool StringToInt(std::string const& s, int& Converted, bool failIfLeftoverChars);

	static bool StringToFloat(std::string const& s, float& converted);

	static bool StringToBool(std::string const& s, bool& converted);

	static std::string IntToString(int Convert);

	static std::string FloatToString(float Convert);

	static std::string BoolToString(bool Convert);

};
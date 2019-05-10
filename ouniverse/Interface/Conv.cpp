//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Conv.h"


bool Conv::StringToInt(std::string const& s, int& Converted, bool failIfLeftoverChars = true)
{
	std::istringstream i(s);
	char c;
	if (!(i >> Converted) || (failIfLeftoverChars && i.get(c)))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Conv::StringToFloat(std::string const& s, float& converted)
{
		auto i = std::istringstream(s);

		i >> converted;
		i >> std::ws;

		return !i.fail() && i.eof();
}


bool Conv::StringToBool(std::string const& s, bool& converted)
{
	if (s == "0" || s == "false")
	{
		converted =  false;
		return true;
	}
	else if (s == "1" || s == "true")
	{
		converted = true;
		return true;
	}

	return false;
}


std::string Conv::IntToString(int Convert)
{
	return std::to_string(Convert);
}

std::string Conv::FloatToString(float Convert)
{
	return std::to_string(Convert);
}

std::string Conv::BoolToString(bool Convert)
{
	if (Convert)
	{
		return "1";
	}
	else
	{
		return "0";
	}
}
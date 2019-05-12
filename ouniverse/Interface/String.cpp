//Copyright 2015-2019, All Rights Reserved.

#include "Interface/String.h"
#include <sstream>
#include <algorithm>
#include <cctype>

StringC::StringC()
{
	s = "";
};

StringC::StringC(const char* inText)
{
	s = inText;
};

StringC::StringC(std::string inText)
{
	s = inText;
};

StringC::StringC(FString Text)
{
	s = TCHAR_TO_UTF8(*Text);
};

StringC::StringC(bool In)
{
	if(In)
	{
		s = "1";
		return;
	}
		s = "0";
}

StringC::StringC(float In)
{
	s =  std::to_string(In);
}

StringC::StringC(int In)
{
	s = std::to_string(In);
}

const char* StringC::ToChar()
{
	return s.c_str();
};

std::string StringC::ToStd()
{
	return s;
};

std::string StringC::ToStd() const
{
	return s;
};


FString StringC::ToFString()
{
	return UTF8_TO_TCHAR(s.c_str());
};


bool StringC::operator<(const StringC& l) const
{
	return s < l.ToStd();
}


bool StringC::operator==(StringC In)
{
	if (s == In.ToStd())
	{
		return true;
	}
	return false;
}

bool StringC::operator!=(StringC In)
{
	if (s == In.ToStd())
	{
		return false;
	}
	return true;
}

StringC& StringC::operator+(StringC In)
{
	s = s + In.ToStd();
	return *this;
}


StringC& StringC::operator+(int In)
{
	s = s + std::to_string(In);
	return *this;
}

StringC& StringC::operator+(std::string In)
{
	s += In;
	return *this;
}


StringC& StringC::operator+(const char* In)
{
	s += In;
	return *this;
}

StringC& StringC::operator+=(StringC In)
{
	s += In.ToStd();
	return *this;
}


StringC& StringC::operator+=(int In)
{
	s += std::to_string(In);
	return *this;
}

StringC& StringC::operator+=(std::string In)
{
	s += In;
	return *this;
}


StringC& StringC::operator+=(const char* In)
{
	s += In;
	return *this;
}



StringC& StringC::operator/(const char* In)
{
	s = (s + "/" + In);
	return *this;
}

StringC& StringC::operator/(StringC& In)
{
	s = (s + "/" + In.ToStd());
	return *this;
}

bool StringC::BeBool(bool& Out)
{
	if (s == "0")
	{
		Out = false;
		return true;
	}
	else if (s == "1")
	{
		Out = true;
		return true;
	}

	return false;
}

bool StringC::BeFullBool(bool& Out)
{
	if (s == "0" || s == "false")
	{
		Out = false;
		return true;
	}
	else if (s == "1" || s == "true")
	{
		Out = true;
		return true;
	}

	return false;
}

bool StringC::BeFloat(float& Out)
{
	auto i = std::istringstream(s);

	i >> Out;
	i >> std::ws;

	return !i.fail() && i.eof();
}


bool StringC::BeInt(int& Out)
{
	std::istringstream i(s);
	//char c;
	if (!(i >> Out))
	{
		return false;
	}
	else
	{
		return true;
	}
}

StringC StringC::Sanitize()
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
		}).base(), s.end());

	return *this;
}
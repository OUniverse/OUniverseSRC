//Copyright 2015-2019, All Rights Reserved.

#include "System/Ini.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "Misc/FileHelper.h"

FString IniFlex::Get()
{
	return Flex;
}

IniFlex::IniFlex(FString InDefault)
{
	Flex = InDefault;
	Default = InDefault;
}

void IniFlex::SetFlex(FString InFlex)
{
	Flex = InFlex;
}

void IniFlex::Reset()
{
	Flex = Default;
}

IniBeacon::IniBeacon(){}

void IniBeacon::SetPath(FString Path)
{
	IniPath = Path;
}

void IniBeacon::Add(FString Key, FString Default, bool IsTemplate)
{
	Map.insert({ FName(*Key), new IniFlex(Default) } );
}

void IniBeacon::Set(FString Key, FString Val)
{
	std::map<FName, IniFlex*>::iterator it;
	it = Map.find(FName(*Key));

	if (it != Map.end())
	{
		it->second->SetFlex(Val);
	}
}

FString IniBeacon::GetAsString(FString Key)
{
	std::map<FName, IniFlex*>::iterator it;
	it = Map.find(FName(*Key));

	if (it != Map.end())
	{
		return it->second->Get();
	}

		return "INI NOT FOUND: " + Key;
}

int IniBeacon::GetAsInt(FString Key)
{

	std::map<FName, IniFlex*>::iterator it;
	it = Map.find(FName(*Key));

	if (it != Map.end())
	{
		FString Value = it->second->Get();
		if (Value.IsNumeric())
		{
			return FCString::Atoi(*Value);
		}
	}

	return 0;
}


float IniBeacon::GetAsFloat(FString Key)
{
	std::map<FName, IniFlex*>::iterator it;
	it = Map.find(FName(*Key));

	if (it != Map.end())
	{
		FString Value = it->second->Get();
		if (Value.IsNumeric())
		{
			return FCString::Atof(*Value);
		}
	}
	
	return 0.0f;

}


bool IniBeacon::GetAsBool(FString Key)
{
	std::map<FName, IniFlex*>::iterator it;
	it = Map.find(FName(*Key));

	if (it != Map.end())
	{
		if (it->second->Get() == "1")
		{
			return true;
		}
	}

	return false;
}



void IniBeacon::SaveIni()
{
	FString NewIni;
	for (std::map<FName, IniFlex*>::iterator it = Map.begin(); it != Map.end(); ++it)
	{

		NewIni+=(it->first.ToString())+" "+(it->second->Get());
		NewIni+=LINE_TERMINATOR;
	}
	FFileHelper::SaveStringToFile(NewIni, *IniPath);
}

void IniBeacon::SaveIniTemplate()
{

}

void IniBeacon::ParseIni()
{

	FString OniText;
	FFileHelper::LoadFileToString(OniText, *IniPath);

	std::istringstream OniStream(TCHAR_TO_UTF8(*OniText));
	std::string Entry;
	while (std::getline(OniStream, Entry)) {

		//Trim white space off the end. 
		Entry.erase(std::find_if(Entry.rbegin(), Entry.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), Entry.end());

		//Find and separate the key/value pair.
		std::size_t DilimeterPos;
		DilimeterPos = Entry.find(" ", 0);
		//std::string Key = Entry.substr(0, DilimeterPos);
		//std::string Val = Entry.substr(DilimeterPos + 1);
		FString Key((Entry.substr(0, DilimeterPos)).c_str());
		FString Val((Entry.substr(DilimeterPos + 1)).c_str());

		Set(Key, Val);
	}
}


void IniBeacon::SetAndSave(FString Key, FString Val, bool bSave=false)
{
	std::map<FName, IniFlex*>::iterator it;
	it = Map.find(FName(*Key));

	if (it != Map.end())
	{

		it->second->SetFlex(Val);

		if (bSave)
		{
			SaveIni();
		}

	}
}

void IniBeacon::Reset()
{
	for (std::map<FName, IniFlex*>::iterator it = Map.begin(); it != Map.end(); ++it)
	{
		it->second->Reset();
	}
}

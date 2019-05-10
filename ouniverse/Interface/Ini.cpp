//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Ini.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "Interface/Conv.h"
#include "Interface/File.h"



IniS::Entry::Entry(std::string InKey)
{
	Key = InKey;
}






IniS::String::String(std::string InKey, std::string InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::String* IniS::String::Create(std::string InKey, std::string InDefault)
{
	return new IniS::String(InKey, InDefault);
}

void IniS::String::Set(std::string In)
{
	if (In != Default)
	{
		Altered = true;
	}
	else
	{
		Altered = false;
	}

	Value = In;
}

void IniS::String::SetDirty(std::string In)
{
	Set(In);
}

void IniS::String::Reset()
{
	Value = Default;
	Altered = false;
}

std::string IniS::String::Get()
{
	return Value;
}

std::string IniS::String::Out()
{
	return Value;
}




IniS::Int::Int(std::string InKey, int InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::Int* IniS::Int::Create(std::string InKey, int InDefault)
{
	return new IniS::Int(InKey, InDefault);
}

void IniS::Int::SetDirty(std::string In)
{

	int Converted;
	if (!Conv::StringToInt(In, Converted, false))
	{
		return;
	}

	if (Converted != Default)
	{
		Altered = true;
	}
	else
	{
		Altered = false;
	}

	Value = Converted;
}

void IniS::Int::Set(int In)
{
	if (In != Default)
	{
		Altered = true;
	}
	else
	{
		Altered = false;
	}

	Value = In;
}

void IniS::Int::Reset()
{
	Value = Default;
	Altered = false;
}

int IniS::Int::Get()
{
	return Value;
}

std::string IniS::Int::Out()
{
	return Conv::IntToString(Value);
}






IniS::Float::Float(std::string InKey, float InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::Float* IniS::Float::Create(std::string InKey, float InDefault)
{
	return new IniS::Float(InKey, InDefault);
}

void IniS::Float::SetDirty(std::string In)
{

	float Converted;
	if (!Conv::StringToFloat(In, Converted))
	{
		return;
	}

	if (Converted != Default)
	{
		Altered = true;
	}
	else
	{
		Altered = false;
	}

	Value = Converted;
}

void IniS::Float::Set(float In)
{
	if (In != Default)
	{
		Altered = true;
	}
	else
	{
		Altered = false;
	}

	Value = In;
}

void IniS::Float::Reset()
{
	Value = Default;
	Altered = false;
}

float IniS::Float::Get()
{
	return Value;
}

std::string IniS::Float::Out()
{
	return Conv::FloatToString(Value);
}





IniS::Bool::Bool(std::string InKey, bool InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::Bool* IniS::Bool::Create(std::string InKey, bool InDefault)
{
	return new IniS::Bool(InKey, InDefault);
}

void IniS::Bool::SetDirty(std::string In)
{

	bool Converted;
	if (!Conv::StringToBool(In, Converted))
	{
		return;
	}

	if (Converted != Default)
	{
		Altered = true;
	}
	else
	{
		Altered = false;
	}

	Value = Converted;
}

void IniS::Bool::Set(bool In)
{
	if (In != Default)
	{
		Altered = true;
	}
	else
	{
		Altered = false;
	}

	Value = In;
}

void IniS::Bool::Reset()
{
	Value = Default;
	Altered = false;
}

bool IniS::Bool::Get()
{
	return Value;
}

std::string IniS::Bool::Out()
{
	return Conv::BoolToString(Value);
}








IniS::IniS(FString* Path, FString FileName, int BoolSize, int IntSize, int FloatSize, int StringSize)
{
	BoolVector.assign(BoolSize, NULL);
	IntVector.assign(IntSize, NULL);
	FloatVector.assign(FloatSize, NULL);
	StringVector.assign(StringSize, NULL);

	Dir = Path;
}


void IniS::AddBool(int Key, IniS::Bool* NewEntry)
{
	BoolVector[Key] = NewEntry;
	KeyMap.insert({ NewEntry->Key , NewEntry });
}

void IniS::AddInt(int Key, IniS::Int* NewEntry)
{
	IntVector[Key] = NewEntry;
	KeyMap.insert({ NewEntry->Key , NewEntry });
}

void IniS::AddFloat(int Key, IniS::Float* NewEntry)
{
	FloatVector[Key] = NewEntry;
	KeyMap.insert({ NewEntry->Key , NewEntry });
}

void IniS::AddString(int Key, IniS::String* NewEntry)
{
	StringVector[Key] = NewEntry;
	KeyMap.insert({ NewEntry->Key , NewEntry });
}

void IniS::Set(int Key, float Val)
{
	FloatVector[Key]->Set(Val);
}

void IniS::Set(int Key, int Val)
{
	IntVector[Key]->Set(Val);
}

void IniS::Set(int Key, bool Val)
{
	BoolVector[Key]->Set(Val);
}

void IniS::Set(int Key, std::string Val)
{
	StringVector[Key]->Set(Val);
}

void IniS::SetDirty(std::string Key, std::string Val)
{
	std::map<std::string, Entry*>::iterator it;
	it = KeyMap.find(Key);

	if (it != KeyMap.end())
	{
		it->second->SetDirty(Val);
	}
}


std::string IniS::GetString(int Key)
{
	return StringVector[Key]->Get();
}

int IniS::GetInt(int Key)
{
	return IntVector[Key]->Get();
}

float IniS::GetFloat(int Key)
{
	return FloatVector[Key]->Get();
}

bool IniS::GetBool(int Key)
{
	return BoolVector[Key]->Get();
}


void IniS::Save()
{
	std::string NewIni;
	for (std::map<std::string, Entry*>::iterator it = KeyMap.begin(); it != KeyMap.end(); ++it)
	{

		NewIni+=(it->second->Out());
		NewIni+=FileC::LineBreak();
	}

	FileC::Empty(*Dir);
	FileC::Append(*Dir, NewIni);
}

void IniS::SaveTemplate()
{

}

void IniS::Parse()
{

	std::ifstream ifs;
	ifs.open(TCHAR_TO_UTF8(&Dir));

	std::string Entry;
	while (std::getline(ifs, Entry)) {

		//Trim white space off the end. 
		Entry.erase(std::find_if(Entry.rbegin(), Entry.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), Entry.end());

		//Find and separate the key/value pair.
		std::size_t DilimeterPos;
		DilimeterPos = Entry.find(" ", 0);

		SetDirty(Entry.substr(0, DilimeterPos), Entry.substr(DilimeterPos + 1));
	}

	ifs.close();
}


void IniS::SetAndSave(std::string Key, std::string Val, bool bSave = false)
{
	SetDirty(Key, Val);

		if (bSave)
		{
			Save();
		}
}

void IniS::Reset()
{
	for (std::map<std::string, Entry*>::iterator it = KeyMap.begin(); it != KeyMap.end(); ++it)
	{
		it->second->Reset();
	}
}

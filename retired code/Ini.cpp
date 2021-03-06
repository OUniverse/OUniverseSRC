//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Ini.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>
#include "Interface/Dir.h"
#include "Interface/File.h"
#include "Interface/String.h"

#include "Min/DebugM.h"

IniS::Entry::Entry(StringC InKey)
{
	Key = InKey;
}






IniS::String::String(StringC InKey, StringC InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::String* IniS::String::Create(StringC InKey, StringC InDefault)
{
	return new IniS::String(InKey, InDefault);
}

void IniS::String::Set(StringC In)
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

void IniS::String::SetDirty(StringC In)
{
	Set(In);
}

void IniS::String::Reset()
{
	Value = Default;
	Altered = false;
}

StringC IniS::String::Get()
{
	return Value;
}

StringC IniS::String::Out()
{
	return Key+" "+Value;
}




IniS::Int::Int(StringC InKey, int InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::Int* IniS::Int::Create(StringC InKey, int InDefault)
{
	return new IniS::Int(InKey, InDefault);
}

void IniS::Int::SetDirty(StringC In)
{

	int Converted;
	if (!In.BeInt(Converted))
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

StringC IniS::Int::Out()
{
	return Key + " " + StringC(Value);
}






IniS::Float::Float(StringC InKey, float InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::Float* IniS::Float::Create(StringC InKey, float InDefault)
{
	return new IniS::Float(InKey, InDefault);
}

void IniS::Float::SetDirty(StringC In)
{

	float Converted;
	if (!In.BeFloat(Converted))
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

StringC IniS::Float::Out()
{
	return Key + " " + StringC(Value);
}





IniS::Bool::Bool(StringC InKey, bool InDefault) : IniS::Entry(InKey)
{
	Default = InDefault;
	Value = InDefault;
}

IniS::Bool* IniS::Bool::Create(StringC InKey, bool InDefault)
{
	return new IniS::Bool(InKey, InDefault);
}

void IniS::Bool::SetDirty(StringC In)
{

	bool Converted;
	if (!In.BeBool(Converted))
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

StringC IniS::Bool::Out()
{
	return Key + " " + StringC(Value);
}








IniS::IniS(DirS* Path, StringC InFileName, int BoolSize, int IntSize, int FloatSize, int StringSize)
{
	BoolVector.Init(BoolSize, NULL);
	IntVector.Init(IntSize, NULL);
	FloatVector.Init(FloatSize, NULL);
	StringVector.Init(StringSize, NULL);

	Dir = Path;
	FileName = InFileName;
}


void IniS::AddBool(int Key, IniS::Bool* NewEntry)
{
	BoolVector[Key] = NewEntry;
	KeyMap.Add(NewEntry->Key, NewEntry);
}

void IniS::AddInt(int Key, IniS::Int* NewEntry)
{
	IntVector[Key] = NewEntry;
	KeyMap.Add( NewEntry->Key , NewEntry );
}

void IniS::AddFloat(int Key, IniS::Float* NewEntry)
{
	FloatVector[Key] = NewEntry;
	KeyMap.Add(NewEntry->Key , NewEntry);
}

void IniS::AddString(int Key, IniS::String* NewEntry)
{
	StringVector[Key] = NewEntry;
	KeyMap.Add( NewEntry->Key , NewEntry );
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

void IniS::Set(int Key, StringC Val)
{
	StringVector[Key]->Set(Val);
}

void IniS::SetDirty(StringC Key, StringC Val)
{
	Entry* EntryPTR = new Entry();
	if(KeyMap.Try(Key, EntryPTR))
	{
		EntryPTR->SetDirty(Val);
	}

	delete EntryPTR;
}


StringC IniS::GetString(int Key)
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
	StringC NewIni = "";
	int Count = KeyMap.Len();
	for (int i = 0; i < Count; i++)
	{
		NewIni += KeyMap.At(i)->Out();
		NewIni.NewLine();
		//NewIni+=(KeyMap.At(i)->Out().NewLine());
	}

	//DBUG(Dir->File(FileName).ToChar())

	FileC IniFile = FileC(Dir->Get()/FileName);
	IniFile.Empty();
	IniFile.Append(NewIni);
}

void IniS::SaveTemplate()
{

}

void IniS::Parse()
{

	std::ifstream ifs;
	ifs.open(Dir->Get().ToChar());

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


void IniS::SetAndSave(StringC Key, StringC Val, bool bSave = false)
{
	SetDirty(Key, Val);

		if (bSave)
		{
			Save();
		}
}

void IniS::Reset()
{
	int Count = KeyMap.Len();
	for (int i = 0; i < Count; i++)
	{
		KeyMap.At(i)->Reset();
	}
}

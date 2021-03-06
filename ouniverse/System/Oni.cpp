//Copyright 2015-2019, All Rights Reserved.

#include "System/Oni.h"

#include "Min/DebugM.h"

OnuC::OnuC(int InKey, int InCategory)
{
	Category_ = InCategory;
	Key_ = InKey;
	Updated_ = false;

}

int OnuC::Key()
{
	return Key_;
}

bool OnuC::Updated()
{
	return Updated_;
}

bool OnuC::IsCategory(int InCategory)
{
	if (Category_ == InCategory)
	{
		return true;
	}

	return false;
}

void OnuC::Load(JsonS InJ)
{

}

JsonS OnuC::ToJson()
{
	JsonS J = JsonS();
	J.Add("k", Key_);
	return J;
}


StringC OnuC::ToString()
{
	return StringC("");
}

int OnuC::ToInt()
{
	return 0;
}

bool OnuC::ToBool()
{
	return false;
}

float OnuC::ToFloat()
{
	return 0.0;
}











OnuBoolC::OnuBoolC(int InKey, bool InDefault, int InCategory) : OnuC(InKey,InCategory)
{
	Current_ = InDefault;
	Default_ = InDefault;
}

void OnuBoolC::Load(JsonS InJ)
{
	Updated_ = true;

	int v = InJ.Int(OniC::KEY_VAL);

	if (v == 0)
	{
		Current_ = false;
	}
	else if(v == 1)
	{
		Current_ = true;
	}
}

JsonS OnuBoolC::ToJson()
{
	JsonS J = OnuC::ToJson();
	J.Add("v", Current_);
	J.Add("d", Default_);
	return J;
}

StringC OnuBoolC::ToString()
{
	if (Current_ == true)
	{
		return StringC("true");
	}
	else
	{
		return StringC("false");
	}
}

int OnuBoolC::ToInt()
{
	if (Current_ == true)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool OnuBoolC::ToBool()
{
	return Current_;
}

float OnuBoolC::ToFloat()
{
	if (Current_ == true)
	{
		return 1.0;
	}
	else
	{
		return 0.0;
	}
}



OnuStringC::OnuStringC(int InKey, StringC InDefault, int InCategory) : OnuC(InKey,InCategory)
{
	Current_ = InDefault;
	Default_ = InDefault;
}

void OnuStringC::Load(JsonS InJ)
{
	Updated_ = true;
	Current_ = InJ.String(OniC::KEY_VAL);
}

JsonS OnuStringC::ToJson()
{
	JsonS J = OnuC::ToJson();
	J.Add("v", Current_);
	J.Add("d", Default_);
	return J;
}

StringC OnuStringC::ToString()
{
	return Current_;
}

int OnuStringC::ToInt()
{
	int Be;
	Current_.BeInt(Be);
	return Be;
}

bool OnuStringC::ToBool()
{
	bool Be;
	Current_.BeBool(Be);
	return Be;
}

float OnuStringC::ToFloat()
{
	float Be;
	Current_.BeFloat(Be);
	return Be;
}




OnuIntC::OnuIntC(int InKey, int InDefault, int InCategory) : OnuC(InKey,InCategory)
{
	Current_ = InDefault;
	Default_ = InDefault;
}

void OnuIntC::Load(JsonS InJ)
{
	Updated_ = true;
	Current_ = InJ.Int(OniC::KEY_VAL);
}

JsonS OnuIntC::ToJson()
{
	JsonS J = OnuC::ToJson();
	J.Add("v", Current_);
	J.Add("d", Default_);
	return J;
}

StringC OnuIntC::ToString()
{
	return Current_;
}

int OnuIntC::ToInt()
{
	return Current_;
}

bool OnuIntC::ToBool()
{
	if (Current_ == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

float OnuIntC::ToFloat()
{
	return Current_;
}





OnuFloatC::OnuFloatC(int InKey, float InDefault, int InCategory) : OnuC(InKey,InCategory)
{
	Current_ = InDefault;
	Default_ = InDefault;
}

void OnuFloatC::Load(JsonS InJ)
{
	Updated_ = true;
	Current_ = InJ.Float(OniC::KEY_VAL);
}

JsonS OnuFloatC::ToJson()
{
	JsonS J = OnuC::ToJson();
	J.Add("v", Current_);
	J.Add("d", Default_);
	return J;
}

StringC OnuFloatC::ToString()
{
	return Current_;
}

int OnuFloatC::ToInt()
{
	return Current_;
}

bool OnuFloatC::ToBool()
{
	if (Current_ == 0.0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

float OnuFloatC::ToFloat()
{
	return Current_;
}






const int OniC::VER_WRITE = 1;
const char* OniC::KEY_KEY = "k";
const char* OniC::KEY_VAL = "v";

OniC::OniC()
{

}

void OniC::AddOnu(OnuC* InOnu)
{
	Lib_.Add(InOnu->Key(),InOnu);
}


void OniC::Load(FileC File)
{
	File_ = File;

	DocC OniDoc = File_.Doc();
	OniDoc.Open();
	
	if (!File.Exists())
	{
		return;
	}

	JsonS JArr = JsonS(OniDoc.ToString());
	JsonS J;
	int Key;
	OnuC* Onu;

	int l = JArr.Len();
	for(int i=0;i<l;i++)
	{
		J = JArr.At(i);
		Key = J.Int(OniC::KEY_KEY);

		if (Lib_.Try(Key,Onu))
		{
			Onu->Load(J);
		}
		
	}

}

void OniC::Save()
{
	int l = Lib_.Len();

	ArrayC<JsonS> JArr;

	JsonS J = JsonS();

	OnuC* OnuLoop;
	for (int i = 0; i < l; i++)
	{
		OnuLoop = Lib_.At(i);

		if (OnuLoop->Updated())
		{
			JArr.Add(OnuLoop->ToJson());
		}
	}

	J.Array(JArr);

	StringC Output = J.Serialize();


}

OnuC* OniC::Get(int InUID)
{
	OnuC* TryOnu;
	Lib_.Try(InUID, TryOnu);
	return  TryOnu;
}


StringC OniC::GetSerializedCategory(int InUID)
{
	int l = Lib_.Len();

	ArrayC<JsonS> JArr;

	JsonS J = JsonS();

	OnuC* OnuLoop;

	for (int i = 0; i < l; i++)
	{
		OnuLoop = Lib_.At(i);

		if (OnuLoop->IsCategory(InUID))
		{
			JArr.Add(OnuLoop->ToJson());
		}
	}

	J.Array(JArr);

	return J.Serialize();
}
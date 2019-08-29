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

void OnuC::Load(JsonS InJ)
{

}

JsonS OnuC::ToJson()
{
	return JsonS();
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
	return JsonS();
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
	return JsonS(Current_);
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
	return JsonS(Current_);
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
	return JsonS(Current_);
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


void OniC::Load(NewFileC File)
{
	File_ = File;

	DocC OniDoc = File_.Doc();
	OniDoc.Open();
	if (OniDoc.Success())
	{

	}
	else
	{

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
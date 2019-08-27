//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Oni.h"


OnuC::OnuC(int InKey)
{
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

OnuBoolC::OnuBoolC(int InKey, bool InDefault) : OnuC(InKey)
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


OnuStringC::OnuStringC(int InKey, StringC InDefault) : OnuC(InKey)
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






OnuIntC::OnuIntC(int InKey, int InDefault) : OnuC(InKey)
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





OnuFloatC::OnuFloatC(int InKey, float InDefault) : OnuC(InKey)
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


void OniC::Load(FileC File)
{
	File_ = File;

	JsonS JArr = JsonS(File_.Read().Out());
	JsonS J;
	int k;

	int l = JArr.Len();
	for(int i=0;i<l;i++)
	{
		J = JArr.At(i);
		k = J.Int(OniC::KEY_KEY);

		if (Lib_.Contains(k))
		{
			Lib_[k]->Load(J);
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

const int OniUserC::AUTOLOGIN_SINGLE_USER = 123142;
const int OniUserC::AUTOLOGIN_LAST_USER = 141221342;


OniUserC::OniUserC()
{

}

OniManagerC::OniManagerC()
{
	Lib_.Init(TYPES_MAX,nullptr);

	Lib_[Types::Internal] = new OniC();
	Lib_[Types::Global] = new OniC();
	Lib_[Types::User] = new OniC();
	Lib_[Types::Scribe] = new OniC();


	OniC* Oni;
	Oni = Lib_[Types::User];

	Oni->AddOnu(new OnuBoolC(OniUserC::AUTOLOGIN_SINGLE_USER, 0));
	Oni->AddOnu(new OnuBoolC(OniUserC::AUTOLOGIN_LAST_USER, 0));		
}

void OniManagerC::Load(OniManagerC::Types InType, FileC InFile)
{
	Lib_[Types::Internal]->Load(InFile);
}
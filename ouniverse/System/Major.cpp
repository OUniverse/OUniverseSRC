//Copyright 2015-2019, All Rights Reserved.



#include "System/Major.h"
#include "Min/DebugM.h"
#include "Interface/String.h"


namespace GlobalSingleton
{
	MajorC gMajor;
}

MajorC* MajorC::Get()
{
	return &GlobalSingleton::gMajor;
}

MajorC* MajorC::Create()
{
	GlobalSingleton::gMajor = *(new MajorC());
	return &GlobalSingleton::gMajor;
}

void MajorC::Test1()
{
	//DelegateS* NewDel = new DelegateS();
	//NewDel->d = DelegateClean::from_method<MajorC, & MajorC::Test2>(this);
	//NewDel->Execute();


	//TestDelegate d = TestDelegate::from_method<MajorC, &MajorC::Test2>(this);
	//d();

	//HTTP("https://ouniverse.com/client/hs/ou1.hs", this, &MajorC::Test2);


	
	EventC<int, bool, int>* CoolEvent2 = new EventC<int, bool, int>();
	EventC<int, bool, int>::Listener2C* Listener2 = CoolEvent2->Create(this, &MajorC::Test4);
	Listener2->Bind();
	EventC<int, bool, int>::Listener2C* Listener3 = CoolEvent2->Create(this, &MajorC::Test5);
	Listener3->Bind();

	CoolEvent2->Trigger(false, 25);
	ArrayC<int> MyResponses = CoolEvent2->Gather(false, 25);
	
	for (int i = 0; i < MyResponses.Len(); i++)
	{
		DBUG(StringC(MyResponses[i]).ToChar())
	}
	
}

int MajorC::Test4(bool why, int ok)
{
	return ok*2;
}

int MajorC::Test5(bool why, int ok)
{
	return ok;
}

void MajorC::Test2(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Response->GetContentAsString());
}

PathsC* MajorC::Path()			{ return Path_; }
UserLib* MajorC::User()		{ return User_; }
ConfigManager* MajorC::Config()	{ return Config_; }
UiManager* MajorC::Ui()			{ return Ui_; }
StateManager* MajorC::State()	{ return State_; }
SystemManager* MajorC::System()	{ return System_; }
InputManager* MajorC::Input()	{ return Input_; }
LogC* MajorC::Log()				{ return Log_; }
AudioManager* MajorC::Audio()	{ return Audio_; }
AControlUE* MajorC::Control()	{ return Control_; }
UWorld* MajorC::Scope()			{ return Scope_; }
AHudUE* MajorC::Hud()			{ return Hud_; }
UViewportUE* MajorC::Viewport()	{ return Viewport_; }
//Copyright 2015-2019, All Rights Reserved.



#include "System/Major.h"

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

	HTTP("https://ouniverse.com/client/hs/ou1.hs", this, &MajorC::Test2);
}


void MajorC::Test2(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Response->GetContentAsString());
}

PathsC* MajorC::Path()			{ return Path_; }
UserManager* MajorC::User()		{ return User_; }
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
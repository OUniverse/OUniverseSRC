//Copyright 2015-2019, All Rights Reserved.



#include "System/Major.h"
#include "GameFramework/PlayerController.h"


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

PathManager* MajorC::Path()			{ return Path_; }
UserManager* MajorC::User()			{ return User_; }
ConfigManager* MajorC::Config()		{ return Config_; }
UiManager* MajorC::Ui()				{ return Ui_; }
StateManager* MajorC::State()		{ return State_; }
SystemManager* MajorC::System()		{ return System_; }
InputManager* MajorC::Input()		{ return Input_; }
LogC* MajorC::Log()					{ return Log_; }
AudioManager* MajorC::Audio()		{ return Audio_; }
APlayerController* MajorC::Control() { return Control_; }
UWorld* MajorC::Scope()				{ return Scope_; }
ADisplayManager* MajorC::Display()	{ return Display_; }
UViewportClient* MajorC::Viewport()	{ return Viewport_; }
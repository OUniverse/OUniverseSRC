//Copyright 2015-2019, All Rights Reserved.



#include "System/Major.h"
#include "GameFramework/PlayerController.h"


namespace GlobalSingleton
{
	Major gMajor;
}

Major* Major::Get()
{
	return &GlobalSingleton::gMajor;
}

Major* Major::Create()
{
	GlobalSingleton::gMajor = *(new Major());
	return &GlobalSingleton::gMajor;
}

PathManager* Major::Path()			{ return Path_; }
UserManager* Major::User()			{ return User_; }
ConfigManager* Major::Config()		{ return Config_; }
UiManager* Major::Ui()				{ return Ui_; }
StateManager* Major::State()		{ return State_; }
SystemManager* Major::System()		{ return System_; }
InputManager* Major::Input()		{ return Input_; }
LogC* Major::Log()					{ return Log_; }
AudioManager* Major::Audio()		{ return Audio_; }
APlayerController* Major::Control() { return Control_; }
UWorld* Major::Scope()				{ return Scope_; }
ADisplayManager* Major::Display()	{ return Display_; }
UViewportClient* Major::Viewport()	{ return Viewport_; }
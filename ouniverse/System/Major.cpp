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


UserW* MajorC::User()				{ return UserW_; }
PathsC* MajorC::Path()				{ return Path_; }
UserLibC* MajorC::UserL()			{ return UserLib_; }
ConfigManager* MajorC::Config()		{ return Config_; }
UiManager* MajorC::Ui()				{ return Ui_; }
MaestroC* MajorC::Maestro()			{ return Maestro_; }
SystemManager* MajorC::System()		{ return System_; }
InputManager* MajorC::Input()		{ return Input_; }
LogC* MajorC::Log()					{ return Log_; }
AudioManager* MajorC::Audio()		{ return Audio_; }
AControlUE* MajorC::Control()		{ return Control_; }
UWorld* MajorC::Scope()				{ return Scope_; }
AHudUE* MajorC::Hud()				{ return Hud_; }
UViewportUE* MajorC::Viewport()		{ return Viewport_; }
TerraC* MajorC::Terra()				{ return Terra_; }
OniManagerC* MajorC::Oni()			{ return Oni_; }
DataC* MajorC::Data()				{ return Data_; }
KernelC* MajorC::Kernel()			{ return Kernel_; }
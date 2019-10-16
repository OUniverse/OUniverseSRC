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

UObject* MajorC::WorldContext()		{ return WorldContext_; }
UserDaisC* MajorC::UserD()			{ return UserDais_; }
UserLibC* MajorC::UserL()			{ return UserLib_; }
LoadoutDaisC* MajorC::LoadoutD()	{ return LoadoutDais_; }
LoadoutLibC* MajorC::LoadoutL()		{ return LoadoutLib_; }
SaveDaisC* MajorC::SaveD()			{ return SaveDais_; }
SaveLibC* MajorC::SaveL()			{ return SaveLib_; }

ConfigManager* MajorC::Config()		{ return Config_; }
UiC* MajorC::Ui()					{ return Ui_; }
MaestroC* MajorC::Maestro()			{ return Maestro_; }
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
TimeC* MajorC::Time()				{ return Time_; }
UTickUE* MajorC::TickUE()			{ return TickUE_; }
FpsC* MajorC::Fps()					{ return Fps_; }
CosmosC* MajorC::Cosmos()			{ return Cosmos_; }
PartyC* MajorC::Party()				{ return Party_; }
EtherC* MajorC::Ether()				{ return Ether_; }
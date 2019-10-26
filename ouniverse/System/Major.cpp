//Copyright 2015-2019, All Rights Reserved.



#include "System/Major.h"
#include "Min/DebugM.h"
#include "Interface/String.h"


namespace GlobalSingleton
{
	UMajor* gMajor;
}

UMajor* UMajor::Get()
{
	return GlobalSingleton::gMajor;
}

UMajor* UMajor::Create()
{
	UMajor* M = NewObject<UMajor>();
	GlobalSingleton::gMajor = M;
	return M;
}

UObject* UMajor::WorldContext()		{ return WorldContext_; }
UserDaisC* UMajor::UserD()			{ return UserDais_; }
UserLibC* UMajor::UserL()			{ return UserLib_; }
LoadoutDaisC* UMajor::LoadoutD()	{ return LoadoutDais_; }
LoadoutLibC* UMajor::LoadoutL()		{ return LoadoutLib_; }
SaveDaisC* UMajor::SaveD()			{ return SaveDais_; }
SaveLibC* UMajor::SaveL()			{ return SaveLib_; }
SaveVatC* UMajor::SaveV()			{ return SaveV_; }

ConfigManager* UMajor::Config()		{ return Config_; }
ACameraUE* UMajor::Camera()			{ return Camera_; }
UUi* UMajor::Ui()					{ return Ui_; }
UMaestro* UMajor::Maestro()			{ return Maestro_; }
LogC* UMajor::Log()					{ return Log_; }
AudioManager* UMajor::Audio()		{ return Audio_; }
AControlUE* UMajor::Control()		{ return Control_; }
UWorld* UMajor::Scope()				{ return Scope_; }
AHudUE* UMajor::Hud()				{ return Hud_; }
UViewportUE* UMajor::Viewport()		{ return Viewport_; }
TerraC* UMajor::Terra()				{ return Terra_; }
OniManagerC* UMajor::Oni()			{ return Oni_; }
AtlasLibC* UMajor::Atlas()			{ return Atlas_; }
DataLibC* UMajor::Dat()				{ return Data_; }
TimeC* UMajor::Time()				{ return Time_; }
UTickUE* UMajor::TickUE()			{ return TickUE_; }
FpsC* UMajor::Fps()					{ return Fps_; }
UCosmos* UMajor::Cosmos()			{ return Cosmos_; }
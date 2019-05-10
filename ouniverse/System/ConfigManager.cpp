//Copyright 2015-2019, All Rights Reserved.

#include "System/ConfigManager.h"
#include "Interface/Ini.h"



ConfigManager* ConfigManager::Create(FString* ConfigIniPath, FString* UserIniDirPTR)
{
	return new ConfigManager(ConfigIniPath, UserIniDirPTR);
}



ConfigManager::ConfigManager(FString* ConfigIniDirPTR, FString* UserIniDirPTR)
{
	//Major->FileManager->GetPath(EPath::UDU_Config)

	IniVector.assign(IniTypes::MAX, NULL);


	IniS* GlobalIni = new IniS(ConfigIniDirPTR, "settings.ini", IniKey::Global::Bool::MAX, IniKey::Global::Int::MAX, IniKey::Global::Float::MAX, IniKey::Global::String::MAX);
	GlobalIni->AddString(IniKey::Global::String::LastUser,		IniS::String::Create("lastUserID",			INI_NULLSTRING));
	GlobalIni->AddBool(IniKey::Global::Bool::FirstRun,			IniS::Bool::Create("bFirstRun",				true));
	GlobalIni->AddBool(IniKey::Global::Bool::SkipIntro,			IniS::Bool::Create("bSkipIntro",			false));
	GlobalIni->AddBool(IniKey::Global::Bool::LoginLastUser,		IniS::Bool::Create("bAutoLoginLastUser",	true));
	GlobalIni->AddBool(IniKey::Global::Bool::LoginSingleUser,	IniS::Bool::Create("bAutoLoginSingleUser",	true));
	GlobalIni->Parse();
	GlobalIni->Save();

	IniVector[IniTypes::Global] = GlobalIni;
	
	
	IniS* UserIni = new IniS(UserIniDirPTR, "user.ini", IniKey::User::Bool::MAX, IniKey::User::Int::MAX, IniKey::User::Float::MAX, IniKey::User::String::MAX);
	GlobalIni->AddString(IniKey::User::String::LastPlaythrough,	IniS::String::Create("lastPlaythroughID", INI_NULLSTRING));

	IniVector[IniTypes::User] = UserIni;
	//LOG(LBOOT, 1, "ConfigManager: On");
}

void ConfigManager::LoadUserINI()
{
	IniVector[IniTypes::User]->Reset();
	IniVector[IniTypes::User]->Parse();
	IniVector[IniTypes::User]->Save();
}

IniS* ConfigManager::GetIni(IniTypes Type)
{
	return IniVector[Type];
}

std::string ConfigManager::GetString(IniTypes Type, int Key)
{
	return GetIni(Type)->GetString(Key);
}

int ConfigManager::GetInt(IniTypes Type, int Key)
{
	return GetIni(Type)->GetInt(Key);
}
float ConfigManager::GetFloat(IniTypes Type, int Key)
{
	return GetIni(Type)->GetFloat(Key);
}
bool ConfigManager::GetBool(IniTypes Type, int Key)
{
	return GetIni(Type)->GetBool(Key);
}
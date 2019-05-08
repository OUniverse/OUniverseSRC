//Copyright 2015-2019, All Rights Reserved.

#include "System/ConfigManager.h"
#include "System/Ini.h"



ConfigManager* ConfigManager::Create(FString ConfigIniPath, FString UserIniPath)
{
	return new ConfigManager(ConfigIniPath, UserIniPath);
}



ConfigManager::ConfigManager(FString ConfigIniPath, FString UserIniPath)
{
	//Major->FileManager->GetPath(EPath::UDU_Config)

	IniVector.assign(2, NULL);

	IniBeacon* GlobalIni = new IniBeacon();
	GlobalIni->SetPath(ConfigIniPath + INI_NAME_GLOBAL);
	GlobalIni->Add(OINI_LAST_USER, INI_NULLSTRING, false);
	GlobalIni->Add(OINI_FIRST_RUN, "1", false);
	GlobalIni->Add(OINI_SKIP_INTRO, "1", false);
	GlobalIni->Add(OINI_AUTOLOG_SINGLE_USER, "1", false);
	GlobalIni->Add(OINI_AUTOLOG_LAST_USER, "1", false);
	GlobalIni->ParseIni();
	GlobalIni->SaveIni();

	IniVector[IniTypes::Global] = GlobalIni;
	
	IniBeacon* UserIni = new IniBeacon();
	UserIni->SetPath(UserIniPath);
	UserIni->Add(UINI_LAST_PLAYTHROUGH, INI_NULLSTRING, false);

	IniVector[IniTypes::User] = UserIni;
	//LOG(LBOOT, 1, "ConfigManager: On");
}

void ConfigManager::LoadUserINI(FString ActiveUserPath)
{
	IniBeacon* UserIni = IniVector[IniTypes::User];

	//FString DirUsers = Major->FileManager->GetPath(EPath::UDO_Users);
	//FString IniPath = UserIni.IniPath+UserID+"/"+FOLDER_USER_THISOUNIV+"/user.ini";

	//LOG(LBOOT, 1, "User ini loaded: "+ IniPath);

	UserIni->Reset();
	UserIni->SetPath(ActiveUserPath);
	UserIni->ParseIni();
	UserIni->SaveIni();
}

IniBeacon* ConfigManager::GetIni(IniTypes Type)
{
	return IniVector[Type];
}

FString ConfigManager::GetAsString(IniTypes Type, FString Key)
{
	return GetIni(Type)->GetAsString(Key);
}

int ConfigManager::GetAsInt(IniTypes Type, FString Key)
{
	return GetIni(Type)->GetAsInt(Key);
}
float ConfigManager::GetAsFloat(IniTypes Type, FString Key)
{
	return GetIni(Type)->GetAsFloat(Key);
}
bool ConfigManager::GetAsBool(IniTypes Type, FString Key)
{
	return GetIni(Type)->GetAsBool(Key);
}
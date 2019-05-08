//Copyright 2015-2019, All Rights Reserved.

#include "System/PathManager.h"


PathManager* PathManager::Create()
{
	return new PathManager();
}


PathManager::PathManager()
{
	DirectoryMyDocuments = FString(FPlatformProcess::UserDir()) + FOLDER_OUNIVERSE + "/";
	DirectoryAppData = FString(FPlatformProcess::UserSettingsDir()) + FOLDER_OUNIVERSE + "/";
	DirectoryContent = FPaths::ProjectContentDir();
}




FString PathManager::DDoc()
{
	return DirectoryMyDocuments;
}

FString PathManager::DApp()
{
	return DirectoryAppData;
}

FString PathManager::DGlobalLogs()
{
	return DirectoryMyDocuments + FOLDER_DOC_THISOUNIV + "/" + FOLDER_LOGS + "/";;
}

FString PathManager::DUsers()
{
	return DirectoryMyDocuments + FOLDER_USERS + "/";
}


FString PathManager::DAppConfig()
{
	return DirectoryAppData + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CONFIG + "/";
}

FString PathManager::DAppCache()
{
	return DirectoryAppData + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CACHE + "/";
}

FString PathManager::DContent()
{
	return DirectoryContent;
}

FString PathManager::DContentReg()
{
	return DirectoryContent + "reg/";
}


FString PathManager::DUiServer()
{
	return "coui://ui/";
}

FString PathManager::DUiReg()
{
	return "coui://ui/reg/";
}


	//validating dirs idk
	//IPlatformFile& PlatformFile = FPlatformPathManager::Get().GetPlatformFile();
	//FPaths::NormalizeDirectoryName(FolderToMake);
	//if (PlatformFile.CreateDirectoryTree(*DocRoot))
	//{
	//}
	/**
	if (PlatformFile.CreateDirectoryTree(*DocUnivLogs))
	{


	}
	if (PlatformFile.CreateDirectoryTree(*DocGlobalUsers))
	{


	}
	*/
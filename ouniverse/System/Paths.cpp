//Copyright 2015-2019, All Rights Reserved.

#include "System/Paths.h"
#include "Interface/File.h"

PathsC* PathsC::Create()
{
	return new PathsC();
}


PathsC::PathsC()
{
	Documents_ = FileC::MakeDir(FString(FPlatformProcess::UserDir()) + FOLDER_OUNIVERSE + "/")+"/";
	AppData_ = FileC::MakeDir(FString(FPlatformProcess::UserSettingsDir()) + FOLDER_OUNIVERSE + "/")+"/";
	Content_ = FileC::MakeDir(FPaths::ProjectContentDir())+"/";

	Logs_ = FileC::MakeDir(Documents_ +  FOLDER_DOC_THISOUNIV + "/" + FOLDER_LOGS + "/")+"/";
	Users_ = FileC::MakeDir(Documents_ + FOLDER_USERS + "/")+"/";
	AppDataConfig_ = FileC::MakeDir(AppData_ + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CONFIG + "/")+"/";
	AppDataCache_ = FileC::MakeDir(AppData_ + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CACHE + "/");
	Reg_ = FileC::MakeDir(Content_ + "reg/")+"/";
	UiServer_ = FileC::MakeDir("coui://ui/")+"/";
	UiReg_ = FileC::MakeDir("coui://ui/reg/")+"/";
}


FString PathsC::Documents() { return Documents_; }

FString PathsC::AppData() { return AppData_; }

FString PathsC::Logs() { return Logs_; }

FString PathsC::Users() { return Users_; };

FString PathsC::AppDataConfig() {return AppData_ + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CONFIG + "/"; }

FString PathsC::AppDataCache() { return AppData_ + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CACHE + "/"; }

FString PathsC::Content() {	return Content_; }

FString PathsC::Reg() { return Content_ + "reg/"; }

FString PathsC::UiServer() { return "coui://ui/"; }

FString PathsC::UiReg() { return "coui://ui/reg/"; }


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
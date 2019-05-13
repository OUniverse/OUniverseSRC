//Copyright 2015-2019, All Rights Reserved.

#include "System/Paths.h"
#include "Interface/File.h"
#include "Interface/String.h"
#include "Interface/Dir.h"

#include "Min/DebugM.h"


PathsC* PathsC::Create()
{
	return new PathsC();
}


PathsC::PathsC()
{


	Doc_ =			new DirS(	StringC(FString(FPlatformProcess::UserDir()) + FOLDER_OUNIVERSE));
	Doc_->Make();
	App_ =			new DirS(	StringC(FString(FPlatformProcess::UserSettingsDir()) + FOLDER_OUNIVERSE));
	App_ ->Make();
	Content_ =		new DirS(	StringC(FPaths::ProjectContentDir()));
	Content_->Make();
	Config_ =		new DirS(	StringC(Doc_->Get()/FOLDER_DOC_THISOUNIV/FOLDER_CONFIG));
	Config_->Make();
	Logs_ =			new DirS(	StringC(Doc_->Get()/FOLDER_DOC_THISOUNIV/FOLDER_LOGS));
	Logs_->Make();
	Users_ =		new DirS(	StringC(Doc_->Get()/FOLDER_DOC_THISOUNIV/FOLDER_USERS));
	Users_->Make();
	//DirS* LL  =  new DirS(StringC::FStringToChar(FString(FPlatformProcess::UserDir()) + FOLDER_OUNIVERSE + "/"));

	//DBUGC(RGB_ERR, LL->Get().c_str());
	//DBUGC(RGB_ERR, Doc()->Get().c_str());
	//DBUGC(RGB_ERR, "HERE");

	
	//AppConfig_ =	*(new DirS(App_.Get() + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CONFIG + "/"));
	//AppCache_ =		*(new DirS(App_.Get() + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CACHE + "/"));
	//Reg_ =			*(new DirS(Content_.Get() + "reg/"));
	//UiServer_ =		*(new DirS("coui://ui//"));
	//UiReg_ =		*(new DirS("coui://ui/reg/"));

	//ActiveUser_ = "";
}


DirS* PathsC::Doc() { return Doc_; };

DirS* PathsC::App() { return App_; };

DirS* PathsC::Logs() { return Logs_; };

DirS* PathsC::Config() { return Config_; };

DirS* PathsC::Users() { return Users_; };

DirS* PathsC::ActiveUser() { return ActiveUser_; };

DirS* PathsC::AppConfig() { return AppConfig_; };

DirS* PathsC::AppCache() { return AppCache_; };

DirS* PathsC::Content() { return Content_; };

DirS* PathsC::Reg() { return Content_; };

DirS* PathsC::UiServer() { return UiServer_; };

DirS* PathsC::UiReg() { return UiReg_; };


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
//Copyright 2015-2019, All Rights Reserved.

#include "System/Paths.h"
#include "Interface/File.h"
#include "Interface/String.h"
#include "Interface/Dir.h"

#include "Min/DebugM.h"


const char* PathsC::UiServer = "coui://ui//";

PathsC* PathsC::Create()
{
	return new PathsC();
}


PathsC::PathsC()
{


	Doc_ =			new DirS(	StringC(FString(FPlatformProcess::UserDir()) + FOLDER_OUNIVERSE));
	Doc_->Make();

	StringC AppDir = StringC(FString(FPlatformProcess::UserSettingsDir()) + FOLDER_DOC_THISOUNIV + "/" + FOLDER_CONFIG);

	App_ =			new DirS(	AppDir);
	App_ ->Make();

	AppConfig_ =	new DirS(	StringC(App_->Get() / FOLDER_DOC_THISOUNIV / FOLDER_CONFIG));
	AppConfig_->Make();

	AppCache_ =		new DirS(	StringC(App_->Get()/FOLDER_DOC_THISOUNIV/FOLDER_CACHE));
	AppConfig_->Make();

	Content_ =		new DirS(	StringC(FPaths::ProjectContentDir()));
	Content_->Make();

	Config_ =		new DirS(	StringC(Doc_->Get()/FOLDER_DOC_THISOUNIV/FOLDER_CONFIG));
	Config_->Make();

	Logs_ =			new DirS(	StringC(Doc_->Get()/FOLDER_DOC_THISOUNIV/FOLDER_LOGS));
	Logs_->Make();

	Users_ =		new DirS(	StringC(Doc_->Get()/FOLDER_DOC_THISOUNIV/FOLDER_USERS));
	Users_->Make();

	Reg_ =			new DirS(	StringC(Content_->Get() + "reg"));
	Reg_->Make();

	Atlas_ = new DirS(StringC(Content_->Get() + "atlas"));
	Atlas_->Make();

	UiReg_ =		new DirS(	StringC("coui://ui/reg/"));

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

DirS* PathsC::UiReg() { return UiReg_; };

DirS* PathsC::Atlas() { return Atlas_; };
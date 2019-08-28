//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Url.h"
#include <sstream>
#include <fstream>
#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "GenericPlatform/GenericPlatformFile.h"

#include "Min/DebugM.h"



namespace GlobalURL_Dir
{
	NewFolderC DocMy;
	NewFolderC AppMy;
	NewFolderC Content;
	NewFolderC Log;
}

namespace GlobalURL_File
{

}


UrlC::UrlC(StringC InPath)
{
	S_ = InPath;
}

UrlC::operator StringC() const
{
	return S_;
}

void UrlC::operator=(StringC In)
{
	S_ = In;
}

const char* UrlC::ToChar()
{
	return S_.ToChar();
}

void UrlC::Make()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString NormDir = S_.ToFString();
	FPaths::NormalizeDirectoryName(NormDir);
	PlatformFile.CreateDirectoryTree(*NormDir);
}

bool UrlC::IsFile()
{
	return true;
}

bool UrlC::IsFolder()
{
	return true;
}

NewFileC UrlC::ToFile()
{
	return NewFileC(*this);
}

NewFolderC UrlC::ToFolder()
{
	return NewFolderC(*this);
}




NewFileC::NewFileC()
{
	S_ = "";
}

NewFileC::NewFileC(StringC InPath)
{
	S_ = InPath;
}

StringC NewFileC::ToString()
{
	return S_;
}

const char* NewFileC::ToChar()
{
	return S_.ToChar();
}

bool NewFileC::Exists()
{

	if (FPaths::FileExists(S_.ToChar()))
	{
		return true;
	}

	return false;
}

DocC NewFileC::Doc()
{
	return DocC(*this);
}

DocStreamC NewFileC::Stream()
{
	return DocStreamC(*this);
}




NewFolderC::NewFolderC()
{
	S_ = "";
}

NewFolderC::NewFolderC(StringC InPath)
{
	S_ = InPath;
}

void NewFolderC::Make()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString NormDir = S_.ToFString();
	FPaths::NormalizeDirectoryName(NormDir);
	PlatformFile.CreateDirectoryTree(*NormDir);
}

StringC NewFolderC::ToString()
{
	return S_;
}

const char* NewFolderC::ToChar()
{
	return S_.ToChar();
}

DocC::DocC(NewFileC InFile)
{
	F_ = InFile;
}

NewFileC DocC::ToFile()
{
	return F_;
}

DocC& DocC::Open()
{
	std::stringstream sstr;

	std::ifstream ifs(F_.ToChar());
	if (!ifs.is_open()) {

		return *this;
	}

	Success_ = true;
	sstr << ifs.rdbuf();
	S_ = StringC(sstr.str());

	ifs.close();

	return *this;
}

StringC DocC::ToString()
{
	return S_;
}

const char* DocC::ToChar()
{
	return S_.ToChar();
}

bool DocC::Append(StringC Text)
{
	std::ofstream out;
	out.open(F_.ToString().ToStd(), std::ios::app);
	out << Text.ToChar();
	out.close();
	return true;
}

bool DocC::Write(StringC Text)
{
	std::ofstream out;
	out.open(F_.ToString().ToStd(), std::ios::trunc);
	out << Text.ToChar();
	out.close();
	return true;
}

bool DocC::Empty()
{
	std::ofstream ofs;
	ofs.open(F_.ToString().ToStd(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	return true;
}

bool DocC::Success()
{
	return Success_;
}

DocStreamC::DocStreamC(NewFileC InFile)
{
	F_ = InFile;
}


void PathC::SetGlobals()
{
	StringC D_OUniverse = "OUniverse";
	StringC D_ThisOUniverse = "OUniverse I";

	StringC D_Config = "Config";
	StringC D_Log = "Logs";

	StringC UserDir = StringC(FString(FPlatformProcess::UserDir()));
	StringC AppDir = StringC(FString(FPlatformProcess::UserSettingsDir()));

	GlobalURL_Dir::DocMy	= NewFolderC(UserDir + D_OUniverse);
	GlobalURL_Dir::AppMy	= NewFolderC(AppDir + D_ThisOUniverse / D_Config);
	GlobalURL_Dir::Content	= NewFolderC(StringC(FPaths::ProjectContentDir()));
	GlobalURL_Dir::Log		= NewFolderC(StringC(GlobalURL_Dir::DocMy.ToString() / D_ThisOUniverse / D_Log));
}


NewFolderC NewFolderC::DirLog()
{
	return GlobalURL_Dir::Log;
}
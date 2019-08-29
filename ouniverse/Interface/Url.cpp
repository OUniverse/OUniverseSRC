//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Url.h"

#include <sstream>
#include <fstream>
#include <string>

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
	NewFolderC Users;
	NewFolderC Config;
	NewFolderC Atlas;
}

namespace GlobalURL_File
{
	NewFileC Log;
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

ArrayC<NewFolderC> NewFolderC::GetFolders()
{
	StringC Seek = S_ / "*";
	//Seek += "*";
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *Seek.ToFString(), false, true);

	ArrayC<NewFolderC> Arr;
	int l = Files.Num();
	for (int i = 0; i < l; i++)
	{
		Arr.Add(NewFolderC(S_ / StringC(Files[i])));
	}

	return Arr;
}

ArrayC<NewFileC> NewFolderC::GetFiles()
{
	StringC Seek = S_ / "*";
	//Seek += "*";
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *Seek.ToFString(), true, false);

	ArrayC<NewFileC> Arr;

	int l = Files.Num();
	for (int i = 0; i < l; i++)
	{
		ArrayC<StringC> FileName = StringC(Files[i]).Split('.');
		Arr.Add(NewFileC(*this, FileName[0],FileName[1]));
	}

	return Arr;
}

ArrayC<NewFileC> NewFolderC::GetFiles(StringC InExtension)
{
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *S_.ToFString(), *InExtension.ToFString());

	ArrayC<NewFileC> Arr;

	int l = Files.Num();
	for (int i = 0; i < l; i++)
	{
		ArrayC<StringC> FileName = StringC(Files[i]).Split('.');
		Arr.Add(NewFileC(*this, FileName[0], FileName[1]));
	}

	return Arr;
}

StringC NewFolderC::GetFinalDir()
{
	StringC FinalDir = S_.RemoveLastChar();
	int Last = FinalDir.FindLast("/\\");
	return FinalDir.SubString(Last + 1,-1);
}

StringC NewFolderC::ToString()
{
	return S_;
}

NewFileC NewFolderC::ToFile(StringC File, StringC Ext)
{
	return NewFileC(*this, File, Ext);
}





NewFileC::NewFileC()
{
	Fo_ = NewFolderC();
	Fi_ = "NULL";
	Ext_ = "NULL";

}

NewFileC::NewFileC(NewFolderC InFolder, StringC InFileName, StringC InExtension)
{
	Fo_ = InFolder;
	Fi_ = InFileName;
	Ext_ = InExtension;
}

StringC NewFileC::ToString()
{
	return Fo_.ToString() / Fi_ +"."+ Ext_ ;
}

bool NewFileC::Exists()
{

	if (FPaths::FileExists(ToString().ToChar()))
	{
		return true;
	}

	return false;
}

DocC NewFileC::Doc()
{
	return DocC(*this);
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

	std::ifstream ifs(F_.ToString().ToChar());
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


void PathC::SetGlobals()
{
	StringC D_OUniverse = "OUniverse";
	StringC D_ThisOUniverse = "OUniverse I";

	StringC D_Config = "Config";
	StringC D_Log = "Logs";

	StringC D_Users = "Users";
	StringC D_Atlas = "Atlas";

	StringC UserDir = StringC(FString(FPlatformProcess::UserDir()));
	StringC AppDir = StringC(FString(FPlatformProcess::UserSettingsDir()));

	GlobalURL_Dir::DocMy	= NewFolderC(UserDir + D_OUniverse);
	GlobalURL_Dir::AppMy	= NewFolderC(AppDir + D_ThisOUniverse / D_Config);
	GlobalURL_Dir::Content	= NewFolderC(StringC(FPaths::ProjectContentDir()));
	GlobalURL_Dir::Log		= NewFolderC(StringC(GlobalURL_Dir::DocMy.ToString() / D_ThisOUniverse / D_Log));
	GlobalURL_Dir::Users	= NewFolderC(StringC(GlobalURL_Dir::DocMy.ToString() / D_ThisOUniverse / D_Users));
	GlobalURL_Dir::Config   = NewFolderC(StringC(GlobalURL_Dir::DocMy.ToString() / D_ThisOUniverse / D_Config));
	GlobalURL_Dir::Atlas	= NewFolderC(StringC(GlobalURL_Dir::Content.ToString() + D_Atlas));

	GlobalURL_File::Log = DirLog().ToFile("log", "txt");
	   
}

NewFolderC PathC::DirLog()
{
	return GlobalURL_Dir::Log;
}

NewFolderC PathC::DirUsers()
{
	return GlobalURL_Dir::Users;
}

NewFolderC PathC::DirConfig()
{
	return GlobalURL_Dir::Config;
}

NewFolderC PathC::DirAtlas()
{
	return GlobalURL_Dir::Atlas;
}

NewFileC PathC::FileLog()
{
	return DirLog().ToFile("log", "txt");
}

NewFileC PathC::FileGlobalConfig()
{
	return DirConfig().ToFile("global", "txt");
}
//Copyright 2015-2019, All Rights Reserved.

#include "Interface/File.h"
#include "Min/DebugM.h"
#include <sstream>
#include <fstream>
#include "HAL/PlatformFilemanager.h"

bool FileC::Append(const char* Path, FString Text)
{
	std::ofstream out;
	out.open(Path, std::ios::app);

	std::string str = TCHAR_TO_UTF8(*Text);
	out << str;
	out.close();
	return true;
}

bool FileC::Append(FString Path, FString Text)
{
	return FileC::Append(TCHAR_TO_UTF8(*Path),Text);
}

bool FileC::Empty(const char* Path)
{
	std::ofstream ofs;
	ofs.open(Path, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	return true;
}

bool FileC::Empty(FString Path)
{
	return FileC::Empty(TCHAR_TO_UTF8(*Path));
}

bool FileC::Delete(const char* Path)
{
	if (remove(Path) != 0)
	{
		return false;
	}
	return true;
}

bool FileC::Delete(FString Path)
{
	return FileC::Delete(TCHAR_TO_UTF8(*Path));
}

FString FileC::MakeDir(FString Path)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FPaths::NormalizeDirectoryName(Path);
	if (PlatformFile.CreateDirectoryTree(*Path))
	{
		return Path;
	}
	
	return "";
	
}

FileReadS::FileReadS(const char* Path)
{
	bSuccess = false;
	DBUG(FString(Path));
	std::stringstream sstr;



	std::ifstream ifs(Path);
	if (!ifs.is_open()) {
		DBUG("FAILED");
		return;
	}

	bSuccess = true;
	sstr << ifs.rdbuf();
	String = sstr.str();

	ifs.close();
}

FileReadS::FileReadS(FString Path)
{
    FileReadS::FileReadS(TCHAR_TO_ANSI(*Path));
}

FString FileReadS::AsFString()
{
	return UTF8_TO_TCHAR(String.c_str());
}

const char* FileReadS::AsChar()
{
	return String.c_str();
}







DirFiles::DirFiles()
{
	Count = 0;
}

DirFiles::DirFiles(FString InPath)
{
	Seek(InPath);
}

DirFiles::DirFiles(const char* InPath)
{
	Seek(InPath);
}

void DirFiles::Seek(FString InPath)
{
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Files, *(InPath + FString("*")), true, false);
	Count = Files.Num();
	Path = InPath;
}



int DirFiles::Num()
{
	return Count;
}

FString DirFiles::operator[](int32 Index)
{
	return Files[Index];
}
FString DirFiles::FullPath(int Index)
{
	return Path + Files[Index];
}

FString DirFiles::Extension(int Index)
{
	return FPaths::GetExtension(Files[Index], false);
}
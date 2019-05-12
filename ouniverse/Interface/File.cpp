//Copyright 2015-2019, All Rights Reserved.

#include "Interface/File.h"
#include "Min/DebugM.h"
#include <sstream>
#include <fstream>
#include "HAL/PlatformFilemanager.h"
#include "Interface/String.h"

bool FileC::Append(StringC Path, StringC Text)
{
	std::ofstream out;
	out.open(Path.ToChar(), std::ios::app);
	out << Text.ToChar();
	out.close();
	return true;
}

bool FileC::Empty(StringC Path)
{
	std::ofstream ofs;
	ofs.open(Path.ToChar(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	return true;
}

bool FileC::Delete(StringC Path)
{
	if (remove(Path.ToChar()) != 0)
	{
		return false;
	}
	return true;
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
	return StringC::StringToFString(String);
}

const char* FileReadS::AsChar()
{
	return StringC::StringToChar(String);
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
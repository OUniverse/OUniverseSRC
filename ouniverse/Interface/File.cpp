//Copyright 2015-2019, All Rights Reserved.

#include "Interface/File.h"
#include <sstream>
#include <fstream>
#include "HAL/PlatformFilemanager.h"
#include "Interface/Dir.h"


FileC::FileC(DirS* InDirectory, StringC InFileName)
{
	Directory = InDirectory;
	FileName = InFileName;
}

StringC FileC::Full()
{
	return Directory->Get() / FileName;
}

bool FileC::Append(StringC Text)
{
	std::ofstream out;
	out.open(Full().ToChar(), std::ios::app);
	out << Text.ToChar();
	out.close();
	return true;
}

bool FileC::Empty()
{
	std::ofstream ofs;
	ofs.open(Full().ToChar(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	return true;
}

bool FileC::Delete()
{
	if (remove(Full().ToChar()) != 0)
	{
		return false;
	}
	return true;
}



FileReadS::FileReadS(const char* Path)
{
	bSuccess = false;

	std::stringstream sstr;



	std::ifstream ifs(Path);
	if (!ifs.is_open()) {

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
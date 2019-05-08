//Copyright 2015-2019, All Rights Reserved.

#include "Util/FileFriend.h"
#include "Util/Encryption.h"


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





FFolderCollector::FFolderCollector()
{
	Count = 0;
}
FFolderCollector::FFolderCollector(FString InPath)
{
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(Folders, *(InPath + FString("*")), false, true);
	Count = Folders.Num();
	Path = InPath;
}

int FFolderCollector::Num()
{
	return Count;
}

FString FFolderCollector::Folder(int index)
{
	return Folders[index];
}

FString FFolderCollector::FolderPath(int index)
{
	return Path+Folders[index];
}







FFileWriter::FFileWriter()
{

}

FFileWriter::FFileWriter(FString InText, FString InPath)
{
	Text = InText;
	Path = InPath;
}

void FFileWriter::Encrypt()
{
	Text = FEncryption(Text, false).Out();
}

void FFileWriter::Write()
{
	FFileHelper::SaveStringToFile(Text, *Path);
}

FFileReader::FFileReader()
{
	bFileSuccess = false;
	AsString = "";
	AsJson = nullptr;
}


FFileReader::FFileReader(FString Path)
{
	bFileSuccess = FFileHelper::LoadFileToString(AsString, *Path);
}

void FFileReader::Decrypt()
{
	AsString = FEncryption(AsString, false).Out();
}


void FFileReader::ToJson()
{
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(AsString);
	bJsonSuccess = FJsonSerializer::Deserialize(JsonReader, AsJson);
}

FString FFileReader::String()
{
	return AsString;
}

TSharedPtr<FJsonObject> FFileReader::Json()
{
	return AsJson;
}

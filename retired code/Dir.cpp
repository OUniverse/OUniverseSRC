//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Dir.h"
#include "Interface/File.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Min/DebugM.h"


DirS::DirS(StringC InPath)
{
	Path_ = InPath;
}


StringC DirS::Get()
{
	return Path_;
}

void DirS::Make()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString NormDir = Path_.ToFString();
	FPaths::NormalizeDirectoryName(NormDir);
	PlatformFile.CreateDirectoryTree(*NormDir);
}
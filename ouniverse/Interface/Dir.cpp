//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Dir.h"
#include "Interface/File.h"
#include "Min/DebugM.h"


DirS::DirS(StringC InPath)
{
	FileC::MakeDir(InPath.ToFString());
	Path_ = InPath;
}

DirS* DirS::Tier(const char* In)
{
	Path_ + In + "/";
	return this;
}


StringC DirS::Get()
{
	return Path_;
}

StringC DirS::File(StringC FileName)
{
	return (Path_/FileName);
}
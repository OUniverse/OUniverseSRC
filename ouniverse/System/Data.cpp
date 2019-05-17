//Copyright 2015-2019, All Rights Reserved.

#include "System/Data.h"

#include "Form/Payload.h"
#include "Interface/Dir.h"

namespace GlobalSingleton
{
	DataC Data;
}

DataC* DataC::Get()
{
	return &GlobalSingleton::Data;
}

DataC* DataC::Create(DirS* InDirAtlas)
{
	GlobalSingleton::Data = *(new DataC(InDirAtlas));
	return &GlobalSingleton::Data;
}

DataC::DataC(DirS* InDirAtlas)
{
	DirAtlas_ = InDirAtlas;
	Payload_ = new PayloadC(DirAtlas_);
}

DataC::DataC()
{

}

void DataC::Scan()
{

}
//Copyright 2015-2019, All Rights Reserved.

#include "Interface/File.h"
#include "CoreMinimal.h"
#include <sstream>
#include <fstream>
#include "HAL/PlatformFilemanager.h"
#include "HAL/FileManager.h"
#include "Interface/Dir.h"

#include "Min/DebugM.h"

FileC::FileC()
{
	Path_ = "NULL";
}

FileC::FileC(StringC InPath)
{
	Path_ = InPath;
}

bool FileC::Append(StringC Text)
{
	std::ofstream out;
	out.open(Path_.ToStd(), std::ios::app);
	out << Text.ToChar();
	out.close();
	return true;
}

bool FileC::Write(StringC Text)
{
	std::ofstream out;
	out.open(Path_.ToStd(), std::ios::trunc);
	out << Text.ToChar();
	out.close();
	return true;
}

bool FileC::Empty()
{
	std::ofstream ofs;
	ofs.open(Path_.ToStd(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	return true;
}

bool FileC::Delete()
{
	if (remove(Path_.ToChar()) != 0)
	{
		return false;
	}
	return true;
}

bool FileC::Exists()
{

	if (FPaths::FileExists(Path_.ToChar()))
	{
		return true;
	}

	return false;
}

FileReadS FileC::Read()
{
	return FileReadS(Path_);
}

FileReadS::FileReadS(StringC Path)
{
	Success_ = false;
	std::stringstream sstr;
	   
	std::ifstream ifs(Path.ToChar());
	if (!ifs.is_open()) {

		return;
	}

	Success_ = true;
	sstr << ifs.rdbuf();
	S = StringC(sstr.str());

	ifs.close();
}

bool FileReadS::Success()
{
	return Success_;
}

StringC& FileReadS::Out()
{
	return S;
}

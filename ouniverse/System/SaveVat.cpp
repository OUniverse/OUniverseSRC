//Copyright 2015-2019, All Rights Reserved.

#include "System/SaveVat.h"
#include "System/SaveDais.h"
#include "System/Save.h"
#include "Interface/Json.h"

#include <fstream>

#include "Min/DebugM.h"

namespace GlobalSingleton
{
	SaveVatC SaveVat;
}

SaveVatC* SaveVatC::Get()
{
	return &GlobalSingleton::SaveVat;
}

SaveVatC* SaveVatC::Create(SaveDaisC* InSaveDais)
{
	GlobalSingleton::SaveVat = *(new SaveVatC(InSaveDais));
	return &GlobalSingleton::SaveVat;
}

SaveVatC::SaveVatC()
{

}

SaveVatC::SaveVatC(SaveDaisC* InSaveDais)
{
	SaveD_ = InSaveDais;
}

void SaveVatC::Load()
{
	FileC SaveFile = SaveD_->Get()->File();

	std::string LineSS;
	std::ifstream FileSS;

	FileSS.open(SaveFile.ToString().ToChar());

	std::getline(FileSS, LineSS);
	std::getline(FileSS, LineSS);
	std::getline(FileSS, LineSS);
	JsonS J = JsonS(StringC(LineSS));

	DBUG(J.Serialize().ToChar());
}
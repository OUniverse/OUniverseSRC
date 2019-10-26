//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Data.h"
#include "System/AtlasLib.h"

DataC::DataC(int Atlas, int Form)
{
	Error_ = 0;
	Found_ = AtlasLibC::Get()->TryForm(DuetUID(Atlas, Form), Form_, Error_);
	
}

DataC::DataC(DuetUID InDuet)
{
	Error_ = 0;
	Found_ = AtlasLibC::Get()->TryForm(InDuet, Form_, Error_);

}

bool DataC::Found()
{
	return Found_;
}

FormF* DataC::Form()
{
	return Form_;
}

int DataC::Error()
{
	return Error_;
}
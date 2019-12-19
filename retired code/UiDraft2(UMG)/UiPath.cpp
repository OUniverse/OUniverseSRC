//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiPath.h"


UiPathS::UiPathS()
{
	Type_ = -1;
	Var_ = -1;
};


void UiPathS::Define(int InPathType, int InVar)
{
	Type_ = InPathType;
	Var_ = InVar;
}

int UiPathS::Type()
{
	return Type_;
}

int UiPathS::Var()
{
	return Var_;
}
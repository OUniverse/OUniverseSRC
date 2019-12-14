//Copyright 2015-2019, All Rights Reserved.


#pragma once


#include "Interface/Map.h"
#include "System/InputData.h"

class FocusC;

class OUNIVERSE_API FocalC
{

public:

	
	FocalC();

	FocusC* RegisterFocus(FocusC* InFocus);

	FocusC* FocalActive_;
	
	void FocalActivate(int ID);

	void FocalTrigger(int ID, int InDir);

	MapC<int, FocusC*> Foci_;

	bool FocalInputCommand(KeyS InKey);

};
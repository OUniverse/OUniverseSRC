//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"


class FormUID
{

public:

	static int Max;

	FormUID();

	FormUID(int InInt);

	FormUID(StringC InS);

	int UID();

	int UID() const;

	bool operator<(const FormUID& l) const;

	bool operator!=(FormUID In);

	bool operator==(FormUID In);

	int ToInt();

	int ForJson();

	int ForUI();

	int ForLog();

	int& Ref();

private:

	int UID_;
};
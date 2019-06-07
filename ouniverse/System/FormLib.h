//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Json.h"

#include "Form/FormF.h"


class PayloadC;

class FormLibC
{

public:

	FormLibC();

	void AddSerializedList(StringC InSer);
	FormF* operator[](U32 InValue);

	void Link(PayloadC* InPayload);

private:

	enum Types {
		Form,
		Ref,
		Object,
		TYPES_MAX,
	};

	int Num_;

	ArrayC<FormF* (*)(JsonS&)> FactoryArray;

	MapC<U32, FormF*> Lib_;

};
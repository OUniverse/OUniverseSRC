//Copyright 2015-2019, All Rights Reserved.


#include "System/FormData.h"

FormDataC::FormDataC(AtlasC* InAtlas, FormF* InForm)
{
	Form_ = InForm;
	Atlas_ = InAtlas;
}

AtlasC* FormDataC::Atlas()
{
	return Atlas_;
}

FormF* FormDataC::Form()
{
	return Form_;
}

void FormDataC::SetOpen(bool InStatus)
{
	Open_ = InStatus;
}
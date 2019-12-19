//Copyright 2015-2019, All Rights Reserved.


#include "System/FormWrap.h"
#include "System/Atlas.h"
#include "Form/FormF.h"




FormWrapS::FormWrapS(AtlasC* InAtlas, FormF* InForm)
{
	Atlas_ = InAtlas;
	Form_ = InForm;

}

AtlasC* FormWrapS::Atlas()
{
	return Atlas_;
}

FormF* FormWrapS::Form()
{
	return Form_;
}
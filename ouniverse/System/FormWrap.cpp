//Copyright 2015-2019, All Rights Reserved.


#include "System/FormWrap.h"
#include "System/Atlas.h"
#include "Data/DataD.h"




FormWrapS::FormWrapS(AtlasC* InAtlas, DataD* InForm)
{
	Atlas_ = InAtlas;
	Form_ = InForm;

}

AtlasC* FormWrapS::Atlas()
{
	return Atlas_;
}

DataD* FormWrapS::Form()
{
	return Form_;
}
//Copyright 2015-2019, All Rights Reserved.

#include "System/AtlasLib.h"
#include "System/Atlas.h"


AtlasLibC::AtlasLibC()
{

}


AtlasC* AtlasLibC::operator[](U64 InValue)
{
	return Lib_[InValue];
}

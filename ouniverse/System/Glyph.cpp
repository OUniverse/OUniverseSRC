//Copyright 2015-2019, All Rights Reserved.

#include "System/Glyph.h"


GlyphC::GlyphC()
{

}

GlyphC::GlyphC(int InUID)
{
	UID_ = InUID;
}

int GlyphC::ForUI()
{
	return UID_;
}
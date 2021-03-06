//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Poly.h"


int PolyC::Type()
{
	return Type_;
}

PolyObjectC::~PolyObjectC()
{
	Items.Cull();
}

void PolyObjectC::AddKey(PolyC* InNewKey)
{
	Items.Add(InNewKey);
}


PolyObjectC::PolyObjectC(StringC InKey, int InDataID) : PolyC(InKey, InDataID)
{ 
	Type_ = PolyType::Object; 
}

PolyArrayC::PolyArrayC(StringC InKey, int InDataID) : PolyC(InKey, InDataID)
{
	Type_ = PolyType::Array;
}

PolyValueC::PolyValueC(StringC InKey, int InDataID) : PolyC(InKey, InDataID)
{

}


PolyStringC::PolyStringC(StringC InKey, int InDataID, StringC InValue) : PolyValueC(InKey, InDataID)
{
	Type_ = PolyType::String;
	Val_ = InValue;
}

PolyIntC::PolyIntC(StringC InKey, int InDataID, int InValue) : PolyValueC(InKey, InDataID)
{
	Type_ = PolyType::Int;
	Val_ = InValue;
}

PolyFloatC::PolyFloatC(StringC InKey, int InDataID, float InValue) : PolyValueC(InKey, InDataID)
{
	Type_ = PolyType::Float;
	Val_ = InValue;
}
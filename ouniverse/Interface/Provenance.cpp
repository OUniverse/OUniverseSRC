//Copyright 2015-2019, All Rights Reserved.

#include "Interface/Provenance.h"


ProvenanceC::ProvenanceC()
{
	
}

ProvenanceC::ProvenanceC(int InWriter, int InDoc)
{
	Writer_ = InWriter;
	Doc_ = InDoc;
}

bool ProvenanceC::IsValid()
{
	if (Doc_ == 0)
	{
		return false;
	}

	return true;
}

bool ProvenanceC::IsCurrent()
{
	if (Writer_ == Doc_)
	{
		return true;
	}

	return false;
}
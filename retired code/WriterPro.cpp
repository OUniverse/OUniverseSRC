//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/WriterPro.h"
#include "Ui/Ui.h"


WriterPro* WriterPro::Create(int InID, UMajor* InMajor)
{
	WriterPro* Neu = new WriterPro(InID, InMajor);
	return Neu;
}

WriterPro::WriterPro(int InID, UMajor* InMajor) : ProtocolC(InID)
{
	Major_ = InMajor;
}
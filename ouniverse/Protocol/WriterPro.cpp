//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/WriterPro.h"

UWriterPro::UWriterPro()
{

}

UWriterPro* UWriterPro::Create()
{
	UWriterPro* Neu = NewObject<UWriterPro>();
	Neu->Init();
	return Neu;
}

void UWriterPro::Init()
{

}
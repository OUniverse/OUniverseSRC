//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer_AtlasData.h"


UAtlas* UWriter_AtlasData::Atlas()
{
	return Atlas_;
}

void UWriter_AtlasData::Ready(UAtlas* InAtlas)
{
	Atlas_ = InAtlas;
	OnReady();
}


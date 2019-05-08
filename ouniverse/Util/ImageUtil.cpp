//Copyright 2015-2019, All Rights Reserved.

#include "ImageUtil.h"
#include "ImageUtils.h"

UTexture2D* UImageUtilBP::ImportFileAsTexture2D(const FString& Path)
{
	return FImageUtils::ImportFileAsTexture2D(Path);
}
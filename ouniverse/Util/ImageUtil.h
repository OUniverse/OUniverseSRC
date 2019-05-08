//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImageUtil.generated.h"
/**
 * 
 */

class UTexture2D;

UENUM(BlueprintType)
enum class EImageFormats : uint8
{
	JPG		UMETA(DisplayName = "JPG        "),
	PNG		UMETA(DisplayName = "PNG        "),
	BMP		UMETA(DisplayName = "BMP        "),
	ICO		UMETA(DisplayName = "ICO        "),
	EXR		UMETA(DisplayName = "EXR        "),
	ICNS		UMETA(DisplayName = "ICNS        ")
};

UCLASS()
class OUNIVERSE_API UImageUtilBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "UiUitl|Load Texture From File", meta = (Keywords = "image png jpg jpeg bmp bitmap ico icon exr icns"))
	static UTexture2D* ImportFileAsTexture2D(const FString& Path);


};

//Copyright 2015-2019, All Rights Reserved.



#pragma once

#include "UObject/NoExportTypes.h"
#include "CoreMinimal.h"
#include "Atlas_.generated.h"


class AtlasC;
class UTexture2D;

UCLASS(BlueprintType)
class OUNIVERSE_API UAtlas : public UObject
{
	GENERATED_BODY()

public:

	static UAtlas* Create(AtlasC* InAtlas);
	void Init(AtlasC* InAtlas);

	AtlasC* Atlas_;

	UFUNCTION(BlueprintCallable)
	FString GetName();

	UFUNCTION(BlueprintCallable)
	FString GetID();

	UFUNCTION(BlueprintCallable)
	int GetUID();

	UFUNCTION(BlueprintCallable)
	FString GetDescription();

	UFUNCTION(BlueprintCallable)
	FString GetAuthor();

	UFUNCTION(BlueprintCallable)
	FString GetWebsite();

	UFUNCTION(BlueprintCallable)
	FString GetDate();

	UFUNCTION(BlueprintCallable)
	FString GetVerVis();

	UFUNCTION(BlueprintCallable)
	int GetVerInc();

	UFUNCTION(BlueprintCallable)
	int GetVerUpdate();

	UFUNCTION(BlueprintCallable)
	FString GetWebSocket();

	UFUNCTION(BlueprintCallable)
	UTexture2D* GetGFXLarge();

	UFUNCTION(BlueprintCallable)
	UTexture2D* GetGFXSmall();

	
};
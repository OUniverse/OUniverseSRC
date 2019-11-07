//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Blueprint/UserWidget.h"
#include "Ui_Image.generated.h"


class UTexture2D;
class UImage;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Image : public UUserWidget
{

	GENERATED_BODY()

public:
	

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ImageSize;
	
	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;

	void Set(UTexture2D* InTexture);
};
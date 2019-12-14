//Copyright 2015-2019, All Rights Reserved.



#pragma once

#include "Ui/UiView.h"
#include "ConShelf_Log.generated.h"

class LoggerC;
class UScrollBox;
class UTexture2D;
UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UConShelf_Log : public UUiView
{

	GENERATED_BODY()

public:
	
	void Init(UUiView* InParentView, LoggerC* InLog);


	UPROPERTY(meta = (BindWidget))
	UScrollBox* V_ScrollBox;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* FlagFatal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* FlagError;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* FlagWarn;


	LoggerC* Logger_;

	void ViewOpen_Technical() override;
};
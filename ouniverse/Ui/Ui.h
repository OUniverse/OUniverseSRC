//Copyright 2015-2019, All Rights Reserved.

/**
Base widget which manages the entire UI.
 */


#pragma once

#include "Blueprint/UserWidget.h"
#include "Ui.generated.h"

class UMajor;
class UWorld;

class UUi_Alpha;
class UWRI_Alpha;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi : public UUserWidget
{

	GENERATED_BODY()

public:

	static UUi* Create(UMajor* M);
	static UUi* Get();

	void Init(UMajor* M);

	void OpenSystemMenu();
	void OpenTitleMenu();
	void OpenWriterMenu();

	UWorld* Scope_;

	UMajor* Major_;

	void CloseActive();

	UPROPERTY()
	UUi_Alpha* ActiveAlpha_;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

};
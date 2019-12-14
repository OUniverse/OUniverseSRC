//Copyright 2015-2019, All Rights Reserved.

/**
Base widget which manages the entire UI.
 */


#pragma once

#include "Blueprint/UserWidget.h"
#include "Ui.generated.h"

class UCanvasPanel;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUi : public UUserWidget
{

	GENERATED_BODY()

public:

	static UUi* Create();
	static UUi* Get();

	void Init();


	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Viewport;
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Shelf;
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Tray;


	void ToViewport(UWidget* InWidget);
	void ToShelf(UWidget* InWidget);
	void ToTray(UWidget* InWidget);

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override {};


};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriLoadoutU.generated.h"

class WriLoadoutP;

class UWriButton;
class UUiScroll;

class AtlasLibC;
class WriDataC;

class UWriLoadout_ScrollEntry;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriLoadout : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriLoadoutP* InPro, AtlasLibC* InAtlasLib);

	WriLoadoutP* Pro_;

	AtlasLibC* AtlasLib_;

	bool FirstDraw_;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vLoad;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vUnlock;

	UPROPERTY(meta = (BindWidget))
	UUiScroll* vScroll;
	
	void OpenUi();

	UWriLoadout_ScrollEntry* MasterEntry_;

	void MasterSet(UWriLoadout_ScrollEntry* InMaster);
	void MasterCleared();

	static enum REG {
		Load,
		Unlock,
		New,
	};

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget);

	void SetData(WriDataC* InData);
};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "WriLoadoutU.generated.h"


class WriLoadoutP;

class UUiButtonNew;
class UUiScroller;

class AtlasLibC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriLoadout : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriLoadoutP* InPro, AtlasLibC* InAtlasLib);

	WriLoadoutP* Pro_;

	AtlasLibC* AtlasLib_;

	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* BT_Load;

	UPROPERTY(meta = (BindWidget))
	UUiScroller* V_Scroll;

	void OpenUi();

	static enum REG {
		Load,
	};
};
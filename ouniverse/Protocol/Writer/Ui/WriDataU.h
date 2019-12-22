//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriDataU.generated.h"

class WriDataP;
class UTextBlock;
class UWriButton;
class UWriFormEdit;
class AtlasLibC;
class UWriDataSearch;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriData : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void UiConstruct(WriDataP* InPro, AtlasLibC* InAtlasLib);

	WriDataP* Pro_;

	AtlasLibC* AtlasLib_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscView;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vSearch0;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vSearch1;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vSearch2;

	UPROPERTY(meta = (BindWidget))
	UWriFormEdit* vDataEdit;

	UPROPERTY(meta = (BindWidget))
	UWriDataSearch* vDataSearch0;

	UPROPERTY(meta = (BindWidget))
	UWriDataSearch* vDataSearch1;

	UPROPERTY(meta = (BindWidget))
	UWriDataSearch* vDataSearch2;

	static enum REG {
		RSearch0,
		RSearch1,
		RSearch2,
	};
};
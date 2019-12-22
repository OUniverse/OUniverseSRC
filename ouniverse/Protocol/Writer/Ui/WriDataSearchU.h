//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "Interface/Array.h"
#include "WriDataSearchU.generated.h"


class WriDataSearchP;
class AtlasLibC;

class UTextBlock;
class UWriButton;
class UEditableText;
class UUiScroll;

class FormDataC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriDataSearch : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	void UiConstruct(WriDataSearchP* InPro, AtlasLibC* InAtlasLib);

	WriDataSearchP* Pro_;
	AtlasLibC* AtlasLib_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscFilters;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vDscOptions;

	UPROPERTY(meta = (BindWidget))
	UEditableText* vQuery;

	UPROPERTY(meta = (BindWidget))
	UUiScroll* vScroll;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vData;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vRevision;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vAmmend;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vNew;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vDelete;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vSearch;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vMaster;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vSupport;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vJson;

	UFUNCTION()
	void OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	void Query();

	ArrayC<FormDataC*> FormRefs_;

	static enum REG {
		RQuery,
		RScroll,
		RData,
		RRevision,
		RAmmend,
		RNew,
		RDelete,
		RSearch,
		RMaster,
		RSupport,
		RJson,
	};
};
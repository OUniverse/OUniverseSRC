//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "UiJsonType.generated.h"

class UEditableText;
class UUiButton;

class UUiJson;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiJsonType : public UUiFocus
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void SetShell(UUiJson* InShell);

	UUiJson* Shell_;

	UPROPERTY(meta = (BindWidget))
	UEditableText* vKey;
	
	UPROPERTY(meta = (BindWidget))
	UUiButton* vDelete;

	static enum Reg {
		RDelete,
		RAdd,
		RString,
		RInt,
		RArray,
		RObject,
		RExpand,
	};
};
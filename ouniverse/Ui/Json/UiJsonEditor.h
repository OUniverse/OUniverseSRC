//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "UiJsonEditor.generated.h"

class UUiJson;

class UVerticalBox;

struct JsonS;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiJsonEditor : public UUiFocus
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;


	UUiJson* Base_;

	bool Empty_;


	UPROPERTY(meta = (BindWidget))
	UVerticalBox* vBox;


	UPROPERTY(EditAnywhere, meta = (Category = "JsonClass"))
	TSubclassOf<UUiJson> JsonClass;

	void FreshStart();
	void JsonStart(JsonS* InJson);


};
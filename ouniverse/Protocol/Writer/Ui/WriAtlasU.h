//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriAtlasU.generated.h"


class WriAtlasP;
class AtlasC;

class UUiFieldWriterString;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriAtlas : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriAtlasP* InPro);

	WriAtlasP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UUiFieldWriterString* V_ID;

	UPROPERTY(meta = (BindWidget))
	UUiFieldWriterString* V_Author;

	void OpenUI(AtlasC* InAtlas);

};
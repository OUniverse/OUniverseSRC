//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Writer_AtlasView.generated.h"

class UCanvasPanel;

UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_AtlasView : public UUi_View
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateWriterAtlasView"))
	static UWriter_AtlasView* Create(UUi_Master* InMax, UCanvasPanel* InPanel);

	void Init(UUi_Master* InMax, UCanvasPanel* InPanel);
};
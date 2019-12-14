//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "Interface/Array.h"
#include "UiScroller.generated.h"


class UUiBaseNew;
class UUiScrollerEntry;

class USizeBox;
class UCanvasPanel;
class UVerticalBox;

class UCanvasPanelSlot;

UCLASS(Blueprintable)
class OUNIVERSE_API UUiScroller : public UUiFocus
{

	GENERATED_BODY()

public:

	void AddEntry(UUiScrollerEntry* InEntry);

	void ClearChildren();

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Size;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Frame;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* V_Case;

	UCanvasPanelSlot* CaseSlot;

	ArrayC<UUiScrollerEntry*> Entries_;
};
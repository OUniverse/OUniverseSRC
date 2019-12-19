//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "Interface/Array.h"
#include "UiScroll.generated.h"


class UUiBase;
class UUiScrollEntry;

class USizeBox;
class UCanvasPanel;
class UVerticalBox;

class UCanvasPanelSlot;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiScroll : public UUiFocus
{

	GENERATED_BODY()

public:

	void AddEntry(UUiScrollEntry* InEntry);

	void ClearChildren();

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Size;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Frame;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* V_Case;

	UCanvasPanelSlot* CaseSlot;

	ArrayC<UUiScrollEntry*> Entries_;


};
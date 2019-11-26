//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Pylon.h"
#include "Interface/Array.h"
#include "Ui_Scroll.generated.h"


class USizeBox;
class UCanvasPanel;
class UVerticalBox;
class UCanvasPanelSlot;
class UUi_ScrollEl;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Scroll: public UUi_Pylon
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Size;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Frame;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* V_Case;
	
	UCanvasPanelSlot* CaseSlot;

	FVector2D ScrollPosSaver;
	bool bScrolling;

	void Build();

	void MeasureInside();
	void MeasureOutside();

	float InnerHeight;
	float OuterHeight;
	float ScrollOffset;

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void AddEntry(UUi_ScrollEl* InEntry);

	void ClearChildren();

	void CalcCenter();

	UUi_ScrollEl* CenteredElement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SameSizeWEntryMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AllowSemStyle;

	float SemSize;

	void SemStyle();

	
	ArrayC<UUi_ScrollEl*> Entries_;

};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiEl.h"
#include "Interface/Array.h"
#include "Ui/UiPath.h"
#include "UiScroll.generated.h"


class USizeBox;
class UCanvasPanel;
class UVerticalBox;
class UCanvasPanelSlot;
class UUiScrollEl;
class UUiBase;

class UUiScroll;

struct UiScrollAnimationS
{
	UiScrollAnimationS();
	UiScrollAnimationS(UUiScroll* InScroll, float InStart, float InGoal, float InTime);

	UUiScroll* Scroll_;

	void Tick(float InDeltaTime);

	bool Exists();

	float Start_;
	float Goal_;
	float Time_;
	float Delta_;
	bool Exists_;
};

UCLASS(Blueprintable)
class OUNIVERSE_API UUiScroll: public UUiEl
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void Init(int InElementID, UUiBase* InParent);

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Size;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Frame;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* V_Case;
	
	UCanvasPanelSlot* CaseSlot;

	FVector2D ScrollPosSaver;
	bool bScrolling;

	UiScrollAnimationS Animation;

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

	void AddEntry(UUiScrollEl* InEntry);

	void ClearChildren();

	void CalcCenter();

	UUiScrollEl* CenteredElement;
	int CenteredIndex;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* AnimationCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool InputSelectorMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SameSizeWEntryMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AllowSemStyle;

	float SemSize;

	void SemStyle();

	
	ArrayC<UUiScrollEl*> Entries_;

	bool InputCommand(KeyS InKey) override;

	UiPathS PathLeft;
	UiPathS PathRight;
	UiPathS PathCancel;


private:

	UUiBase* Parent_;

	//InputMode InputMode_;

	void MouseMode();

	void ControlMode();

	int ControlHoveredIndex;

};
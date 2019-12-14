//Copyright 2015-2019, All Rights Reserved.

/**
Base widget which manages the entire UI.
 */


#pragma once

#include "Blueprint/UserWidget.h"
#include "Interface/Array.h"
#include "Curves/CurveFloat.h"
#include "Ui_Rolodex.generated.h"


class UVerticalBox;
class UUi_RolodexEl;
class USizeBox;


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Rolodex : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* SizeCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* OpacityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DisplayCount;

	int MidPoint;

	int SideCount;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* V_Case;

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Top;

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Bot;

	int Index;
	bool bAnimating;
	bool bDirection;

	void Forward();
	void Backward();
	
	void Build();

	void MoveComplete();

	void AddEntry(UUi_RolodexEl* InRolodexEl);

	//UCanvasPanelSlot* Slot_;

	//UFUNCTION(BlueprintCallable)
	//void Require(UVerticalBox* InVerticalBox);

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY()
	TArray<UUi_RolodexEl*> Entries_;

	ArrayC<float> Steps;
	ArrayC<UUi_RolodexEl*> ActiveEntries_;

};
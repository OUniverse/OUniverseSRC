//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ubc.h"
#include "Ui_Opt.generated.h"


class UUi_View;


UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Opt : public UUbc
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "ViewID"))
	int ViewUID;

	UUi_View* View_;

	UFUNCTION(BlueprintCallable)
	void SetView(UUi_View* InView);

	bool Deselect_Internal();

	UFUNCTION(BlueprintCallable)
	void Deselect();

	bool Select_Internal();

	UFUNCTION(BlueprintCallable)
	void Select();

	UFUNCTION(BlueprintCallable)
	void Click();

	UFUNCTION(BlueprintCallable)
	void HoverEnter();

	UFUNCTION(BlueprintCallable)
	void HoverExit();

	UFUNCTION(BlueprintImplementableEvent)
	void OnClick();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoverExit();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoverEnter();


};
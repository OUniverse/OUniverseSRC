//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiScrollEl.h"
#include "SYM_UserSelect_Le.generated.h"

class UserC;
class USYM_UserSelect;
class UTextBlock;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_UserSelect_Le : public UUiScrollEl
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static USYM_UserSelect_Le* Create(USYM_UserSelect* InView, UserC* InUser);

	void Init(USYM_UserSelect* InView, UserC* InUser);

	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;

	UserC* User_;

	USYM_UserSelect* View_;

	void UpdateStyleByViewPosition(float InViewPosition) override;

	void PreciseClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
};
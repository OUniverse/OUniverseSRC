//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiFocus.h"
#include "Enum/DirectionUE.h"
#include "Protocol/Ley.h"
#include "SymLoadoutSelectU_Scroller.generated.h"

class UUiButton;
class UTextBlock;
class UserLibC;
class SymUserSelectP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymLoadoutSelect_Scroller : public UUiFocus
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;

	void UiConstruct(SymUserSelectP* InPro, UserLibC* InUserLib);

	UFUNCTION(BlueprintImplementableEvent)
	void Update(EDirection Direction, const FText& InName, const FText& InScore);

	bool InputCommand(KeyS InKey) override;

	void RefreshUser(EDirection Direction);

	SymUserSelectP* Pro_;
	UserLibC* UserLib_;

	int UserIndex_;

	LeyS LeyL;
	LeyS LeyR;

	void RollUp();
	void RollDown();
	void Accept();
};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiFocus.h"
#include "Enum/DirectionUE.h"
#include "Protocol/Ley.h"
#include "SymUserSelectU_Solodex.generated.h"

class UUiButton;
class UTextBlock;
class UserLibC;
class SymUserSelectP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymUserSelect_Solodex : public UUiFocus
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

	void RollUp();
	void RollDown();
	void Accept();
};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiFocus.h"
#include "Enum/DirectionUE.h"
#include "Protocol/Ley.h"
#include "SymLoadoutSelectU_Solodex.generated.h"

class UUiButton;
class UTextBlock;
class LoadoutLibC;
class SymLoadoutSelectP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymLoadoutSelect_Solodex : public UUiFocus
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;

	void UiConstruct(SymLoadoutSelectP* InPro, LoadoutLibC* InUserLib);

	UFUNCTION(BlueprintImplementableEvent)
	void Update(EDirection Direction, const FText& InName, const FText& InScore);

	bool InputCommand(KeyS InKey) override;

	void RefreshUser(EDirection Direction);

	SymLoadoutSelectP* Pro_;
	LoadoutLibC* LoadoutLib_;

	int UserIndex_;

	void RollUp();
	void RollDown();
	void Accept();
};
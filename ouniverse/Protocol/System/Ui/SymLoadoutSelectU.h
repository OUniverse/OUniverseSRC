//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "SymLoadoutSelectU.generated.h"

class SymLoadoutSelectP;
class LoadoutLibC;

class USymLoadoutSelect_Solodex;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymLoadoutSelect : public UUiBase
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;
	
	void UiConstruct(SymLoadoutSelectP* InPro, LoadoutLibC* InLoadoutLib);

	UPROPERTY(meta = (BindWidget))
	USymLoadoutSelect_Solodex* V_Solodex;

	SymLoadoutSelectP* Pro_;
	LoadoutLibC* LoadoutLib_;


};
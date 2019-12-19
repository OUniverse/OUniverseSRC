//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "SymUserSelectU.generated.h"

class SymUserSelectP;
class UserLibC;

class USymUserSelect_Solodex;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymUserSelect : public UUiBase
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;
	
	void UiConstruct(SymUserSelectP* InPro, UserLibC* InUserLib);

	UPROPERTY(meta = (BindWidget))
	USymUserSelect_Solodex* V_Solodex;

	SymUserSelectP* Pro_;
	UserLibC* UserLib_;


};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "SymUserCreateU.generated.h"

class SymUserCreateP;
class UserLibC;


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymUserCreate : public UUiBaseNew
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;
	
	void UiConstruct(SymUserCreateP* InPro);

	SymUserCreateP* Pro_;
	UserLibC* UserLib_;

};
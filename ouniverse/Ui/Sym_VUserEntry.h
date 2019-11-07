//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ubc.h"
#include "Sym_VUserEntry.generated.h"

class UScrollBox;
class UserC;
class USym_VUser;

UCLASS(Blueprintable)
class OUNIVERSE_API USym_VUserEntry : public UUbc
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateSymVSetupEntry"))

	static USym_VUserEntry* Create(UWorld* InScope, USym_VUser* InView, UScrollBox* InBox);

	void Init (USym_VUser* InView, UScrollBox* InBox);

	void OnPreReady(USym_VUser* InView);

	UserC* User_;

	USym_VUser* View_;

	UFUNCTION(BlueprintPure)
	USym_VUser* View();

	UFUNCTION(BlueprintImplementableEvent)
	void Ready();

};
//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "ClassGeneral.generated.h"


class UUi;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UClassGeneral : public UObject
{

	GENERATED_BODY()

public:

	static void Initialize();

	UPROPERTY(EditAnywhere, meta = (Category = "Ui"))
	TSubclassOf<UUi> UiUI;

	static UClassGeneral* Get();

};
//Copyright 2015-2019, All Rights Reserved.



#pragma once

#include "UObject/NoExportTypes.h"
#include "Interface/Url.h"
#include "Interface/Map.h"
#include "Interface/String.h"

#include "Babel.generated.h"


UCLASS()
class OUNIVERSE_API UBabel : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Babel")
	static FString Decode(int InCode);

	static UBabel* Create(FileC BabelDoc);
	void Init(FileC BabelDoc);

	MapC<int, FString> Lib_;
};
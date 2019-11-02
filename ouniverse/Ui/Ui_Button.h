//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ubc.h"
#include "Ui_Button.generated.h"

class UUi_View;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Button : public UUbc
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Command;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UUi_View* View_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UID;

};
//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_UserEdit.generated.h"



class USYM_Alpha;
class UserLibC;
class UUi_Scroll;

class USYM_UserSelect_Le;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_UserEdit : public UUi_View
{

	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	UUi_Scroll* V_Scroll;

	USYM_UserSelect_Le* ActiveEntry_;

	USYM_Alpha* CastedView_;
};
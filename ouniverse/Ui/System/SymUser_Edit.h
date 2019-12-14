//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymUser_Edit.generated.h"



class UserDaisC;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_UserEdit : public UUiView
{

	GENERATED_BODY()

public:

	void Init(UUiView* InParentView, UserDaisC* InUserDais);

private:

	UserDaisC* UserDais_;

};
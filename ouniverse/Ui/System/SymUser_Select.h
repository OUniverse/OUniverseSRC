//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiView.h"
#include "SymUser_Select.generated.h"

class UserLibC;
class UserC;
class UUiScroll;


UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_UserSelect : public UUiView
{

	GENERATED_BODY()


public:



	void Init(UUiView* InParentView, UserLibC* InUserLib);

	UPROPERTY(meta = (BindWidget))
	UUiScroll* V_Scroll;

	UserLibC* UserLib_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* CurveScrollScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* CurveScrollOpacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* CurveScrollColor;

	void UserSelected(UserC* InUser);

	static enum Interfaces {
		Scroll,
		Accept,
		Back,
		MAX,
	};
};
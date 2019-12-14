//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_UserSelect_Le.h"

#include "Ui/System/SymUser_Select.h"
#include "System/User.h"
#include "System/Scope.h"

#include "Ui/Ui_Bool.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/ScrollBox.h"
#include "System/Class.h"

#include "Min/DebugM.h"

void USYM_UserSelect_Le::NativeConstruct()
{
	V_Text->SetText(FText::FromString(User_->ID().ToChar()));
	//V_Image->SetBrushFromTexture(User_->GFXSmall());
	Super::NativeConstruct();
}

USYM_UserSelect_Le* USYM_UserSelect_Le::Create(USYM_UserSelect* InView, UserC* InUser)
{
	USYM_UserSelect_Le* Neu = CreateWidget<USYM_UserSelect_Le>(ScopeC::World(), ClassC::SYM_UserSelect_Le());
	Neu->Init(InView, InUser);
	return Neu;
}

void USYM_UserSelect_Le::Init(USYM_UserSelect* InView, UserC* InUser)
{
	View_ = InView;
	User_ = InUser;
}

void USYM_UserSelect_Le::UpdateStyleByViewPosition(float InViewPosition)
{
	SetRenderOpacity(View_->CurveScrollOpacity->GetFloatValue(InViewPosition));
	SetRenderScale(FVector2D(View_->CurveScrollScale->GetFloatValue(InViewPosition), View_->CurveScrollScale->GetFloatValue(InViewPosition)));
}

void USYM_UserSelect_Le::PreciseClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	View_->UserSelected(User_);
}
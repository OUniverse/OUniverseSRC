//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SYM_VMainVUserEntry.h"


#include "System/User.h"

#include "Ui/Ui_Catch.h"

#include "Ui/Ui_Bool.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/ScrollBox.h"
#include "System/Class.h"


void USYM_VMainVUserEntry::NativeConstruct()
{
	V_Catch->SetRelay(this);
	V_Text->SetText(FText::FromString(User_->ID().ToChar()));
	//V_Image->SetBrushFromTexture(User_->GFXSmall());
	Super::NativeConstruct();
}

USYM_VMainVUserEntry* USYM_VMainVUserEntry::Create(UWorld* InScope, USYM_VMainVUser* InView, UserC* InUser)
{
	USYM_VMainVUserEntry* Neu = CreateWidget<USYM_VMainVUserEntry>(InScope, ClassC::SYM_VUserEntry());
	Neu->Init(InView, InUser);
	return Neu;
}

void USYM_VMainVUserEntry::Init(USYM_VMainVUser* InView, UserC* InUser)
{
	View_ = InView;
	User_ = InUser;
}
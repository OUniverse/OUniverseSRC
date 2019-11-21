//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_View.h"
#include "SYM_VUserVSelect.generated.h"

class UserLibC;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_VUserVSelect : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_VUserVSelect* Create(UUi_View* InParentView);

	void Init(UUi_View* InParentView);

	UserLibC* UserLib_;
};
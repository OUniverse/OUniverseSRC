//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "SymProU.generated.h"

class USymPre;
class USymUserMenu;
class USymLoadoutMenu;
class USymMenu;
class USymTokens;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymPro : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;


	UPROPERTY(meta = (BindWidget))
	USymPre* Page_Pre;

	UPROPERTY(meta = (BindWidget))
	USymUserMenu* Page_UserMenu;

	UPROPERTY(meta = (BindWidget))
	USymLoadoutMenu* Page_LoadoutMenu;

	UPROPERTY(meta = (BindWidget))
	USymMenu* Page_Menu;

	UPROPERTY(meta = (BindWidget))
	USymTokens* V_Tokens;


};
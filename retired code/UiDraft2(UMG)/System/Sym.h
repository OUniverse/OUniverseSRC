//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiAlpha.h"
#include "Sym.generated.h"


class SystemPro;
class SymC;

class USYM_AtlasLoad;
class USYM_Main;
class USYM_Pre;
class USYM_User;

class USYM_MainTokenUser;
class USYM_MainTokenLoadout;
class AtlasLibC;
class UserLibC;
class UserDaisC;
class LoadoutLibC;
class LoadoutDaisC;


UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USystemUi : public UUiAlpha
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;

	static USystemUi* Create(SystemPro* InPro, AtlasLibC* InAtlasLib, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais);
	void Init(SystemPro* InPro, AtlasLibC* InAtlasLib, UserLibC* InUserLib, UserDaisC* InUserDais, LoadoutLibC* InLoadoutLib, LoadoutDaisC* InLoadoutDais);

	AtlasLibC* AtlasLib_;
	UserLibC* UserLib_;
	UserDaisC* UserDais_;
	LoadoutLibC* LoadoutLib_;
	LoadoutDaisC* LoadoutDais_;

	SystemPro* Profile_;

	UPROPERTY(meta = (BindWidget))
	USYM_MainTokenUser* V_TokenUser;
	UPROPERTY(meta = (BindWidget))
	USYM_MainTokenLoadout* V_TokenLoadout;

	UPROPERTY(meta = (BindWidget))
	USYM_AtlasLoad* View_AtlasLoad;
	UPROPERTY(meta = (BindWidget))
	USYM_Pre* View_Pre;
	UPROPERTY(meta = (BindWidget))
	USYM_Main* View_Main;
	UPROPERTY(meta = (BindWidget))
	USYM_User* View_User;

	void UserSelected();

	void ShowTokens();

};
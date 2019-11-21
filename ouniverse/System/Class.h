//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "UObject/SoftObjectPtr.h"

class ACharacter3D;
class UCharacterA;

class UUi;
class UCNS_Alpha;

class UFF_Bool;
class UFF_Link;
class UFF_LinkList;
class UFF_Text;

class ULOG_Alpha;
class UPLS_Alpha;

class USYM_Alpha;
class USYM_AlphaOpt;
class USYM_VMain;
class USYM_VMainVLoadout;
class USYM_VMainVUser;
class USYM_VMainVUserEntry;
class USYM_VUser;
class USYM_VUserVCreate;
class USYM_VUserVSelect;

class UTIM_Alpha;
class UTIM_VMain;
class UTIM_VMainVHome;
class UTIM_VMainVLoad;
class UTIM_VMainVPre;

class UWRI_Alpha;
class UWRI_AlphaOpt;
class UWRI_VAtlas;
class UWRI_VForm;
class UWRI_VFormEForm;
class UWRI_VFormEntry;
class UWRI_VSetup;
class UWRI_VSetupEntry;

class OUNIVERSE_API ClassC
{


public:

	static void Setup();

	static bool IsSetup();
	static TSubclassOf<UCharacterA> F_CharacterA();
	static TSubclassOf<ACharacter3D> F_Character3D();

	static TSubclassOf<UUi>						U_Ui();
	static TSubclassOf<UCNS_Alpha>				CNS_Alpha();

	static TSubclassOf<UFF_Bool>				FF_Bool();
	static TSubclassOf<UFF_Link>				FF_Link();
	static TSubclassOf<UFF_LinkList>			FF_LinkList();
	static TSubclassOf<UFF_Text>				FF_Text();

	static TSubclassOf<ULOG_Alpha>				LOG_Alpha();
	static TSubclassOf<UPLS_Alpha>				PLS_Alpha();

	static TSubclassOf<USYM_Alpha>				SYM_Alpha();
	static TSubclassOf<USYM_AlphaOpt>			SYM_AlphaOpt();
	static TSubclassOf<USYM_VMain>				SYM_VMain();
	static TSubclassOf<USYM_VMainVLoadout>		SYM_VMainVLoadout();
	static TSubclassOf<USYM_VMainVUserEntry>	SYM_VUserEntry();
	static TSubclassOf<USYM_VUser>				SYM_VUser();
	static TSubclassOf<USYM_VUserVCreate>		SYM_VUserVCreate();
	static TSubclassOf<USYM_VUserVSelect>		SYM_VUserVSelect();

	static TSubclassOf<UTIM_Alpha>				TIM_Alpha();
	static TSubclassOf<UTIM_VMain>				TIM_VMain();
	static TSubclassOf<UTIM_VMainVHome>			TIM_VMainVHome();
	static TSubclassOf<UTIM_VMainVLoad>			TIM_VMainVLoad();
	static TSubclassOf<UTIM_VMainVPre>			TIM_VMainVPre();

	static TSubclassOf<UWRI_Alpha>				WRI_Alpha();
	static TSubclassOf<UWRI_AlphaOpt>			WRI_AlphaOpt();
	static TSubclassOf<UWRI_VAtlas>				WRI_VAtlas();
	static TSubclassOf<UWRI_VForm>				WRI_VForm();
	static TSubclassOf<UWRI_VFormEForm>			WRI_VFormEForm();
	static TSubclassOf<UWRI_VFormEntry>			WRI_VFormEntry();
	static TSubclassOf<UWRI_VSetup>				WRI_VSetup();
	static TSubclassOf<UWRI_VSetupEntry>		WRI_VSetupEntry();
};
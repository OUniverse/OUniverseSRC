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

class USym_Master;
class USym_VLoadout;
class USym_VUser;
class USym_VUserEntry;

class UTim_Master;
class UTim_VHome;

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

	static TSubclassOf<USym_Master>				Sym_Master();
	static TSubclassOf<USym_VLoadout>			Sym_VLoadout();
	static TSubclassOf<USym_VUser>				Sym_VUser();
	static TSubclassOf<USym_VUserEntry>			Sym_VUserEntry();

	static TSubclassOf<UTim_Master>				Tim_Master();
	static TSubclassOf<UTim_VHome>				Tim_VHome();

	static TSubclassOf<UWRI_Alpha>				WRI_Alpha();
	static TSubclassOf<UWRI_AlphaOpt>			WRI_AlphaOpt();
	static TSubclassOf<UWRI_VAtlas>				WRI_VAtlas();
	static TSubclassOf<UWRI_VForm>				WRI_VForm();
	static TSubclassOf<UWRI_VFormEForm>			WRI_VFormEForm();
	static TSubclassOf<UWRI_VFormEntry>			WRI_VFormEntry();
	static TSubclassOf<UWRI_VSetup>				WRI_VSetup();
	static TSubclassOf<UWRI_VSetupEntry>		WRI_VSetupEntry();
};
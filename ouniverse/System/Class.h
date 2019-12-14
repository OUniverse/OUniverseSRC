//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "UObject/SoftObjectPtr.h"

class ACharacter3D;
class UCharacterA;

class UUi;

class UFF_Bool;
class UFF_Link;
class UFF_LinkList;
class UFF_Text;

class UConShelf;
class UConShelf_LogEntry;
class UConTray;

class UPLS_Alpha;

class USystemUi;
class USYM_UserSelect_Le;



class UWRI;
class UWRI_AtlasEdit;
class UWRI_AtlasMount;
class UWRI_FormEdit;
class UWRI_FormEdit_Form;
class UWRI_FormEdit_Le;
class UWRI_Loadout;
class UWRI_Loadout_Le;
class UWRI_Main;
class UWRI_Splash;

class OUNIVERSE_API ClassC
{


public:

	static void Setup();

	static bool IsSetup();
	static TSubclassOf<UCharacterA> F_CharacterA();
	static TSubclassOf<ACharacter3D> F_Character3D();

	static TSubclassOf<UUi>						U_Ui();
	
	static TSubclassOf<UConShelf>				ConShelf();
	static TSubclassOf<UConShelf_LogEntry>		ConShelf_LogEntry();
	static TSubclassOf<UConTray>				ConTray();

	static TSubclassOf<UFF_Bool>				FF_Bool();
	static TSubclassOf<UFF_Link>				FF_Link();
	static TSubclassOf<UFF_LinkList>			FF_LinkList();
	static TSubclassOf<UFF_Text>				FF_Text();

	
	static TSubclassOf<UPLS_Alpha>				PLS_Alpha();

	static TSubclassOf<USystemUi>						SYM_Alpha();
	static TSubclassOf<USYM_UserSelect_Le>			SYM_UserSelect_Le();

		static TSubclassOf<UWRI>				WRI_Alpha();
	static TSubclassOf<UWRI_AtlasEdit>			WRI_AtlasEdit();
	static TSubclassOf<UWRI_AtlasMount>			WRI_AtlasMount();	
	static TSubclassOf<UWRI_FormEdit>			WRI_FormEdit();
	static TSubclassOf<UWRI_FormEdit_Form>		WRI_FormEdit_Form();
	static TSubclassOf<UWRI_FormEdit_Le>		WRI_FormEdit_Le();
	static TSubclassOf<UWRI_Loadout>			WRI_Loadout();
	static TSubclassOf<UWRI_Loadout_Le>			WRI_Loadout_Le();
	static TSubclassOf<UWRI_Main>				WRI_Main();
	static TSubclassOf<UWRI_Splash>				WRI_Splash();
};
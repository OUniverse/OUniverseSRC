//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "UObject/SoftObjectPtr.h"

class ACharacter3D;
class UCharacterA;

class UUi;
class UConsole_Max;
class ULogv_Max;
class UPulse_Max;
class USym_EmptyView;
class USym_Max;
class USym_UserData;
class USym_UserList;
class USym_UserView;
class UWriter_Max;
class UWriter_Head;
class UWriter_AtlasView;
class UWriter_AtlasList;
class UWriter_AtlasData;
class UWriter_FormView;
class UWriter_FormList;
class UWriter_FormData;


class OUNIVERSE_API ClassC
{


public:

	static void Setup();

	static bool IsSetup();
	static TSubclassOf<UCharacterA> F_CharacterA();
	static TSubclassOf<ACharacter3D> F_Character3D();

	static TSubclassOf<UUi> U_Ui();
	static TSubclassOf<UConsole_Max>		Console_Max();
	static TSubclassOf<ULogv_Max>			Logv_Max();
	static TSubclassOf<UPulse_Max>			Pulse_Max();
	static TSubclassOf<USym_EmptyView>		Sym_EmptyView();
	static TSubclassOf<USym_Max>			Sym_Max();
	static TSubclassOf<USym_UserData>		Sym_UserData();
	static TSubclassOf<USym_UserList>		Sym_UserList();
	static TSubclassOf<USym_UserView>		Sym_UserView();
	static TSubclassOf<UWriter_Max>			Writer_Max();
	static TSubclassOf<UWriter_Head>		Writer_Head();
	static TSubclassOf<UWriter_AtlasView>	Writer_AtlasView();
	static TSubclassOf<UWriter_AtlasList>	Writer_AtlasList();
	static TSubclassOf<UWriter_AtlasData>	Writer_AtlasData();
	static TSubclassOf<UWriter_FormView>	Writer_FormView();
	static TSubclassOf<UWriter_FormList>	Writer_FormList();
	static TSubclassOf<UWriter_FormData>	Writer_FormData();
};
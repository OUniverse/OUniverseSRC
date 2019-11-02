//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "UObject/SoftObjectPtr.h"

class ACharacter3D;
class UCharacterA;

class UUi;
class UConsole_Master;
class ULogv_Master;
class UPulse_Master;
class USym_EmptyView;
class USym_Master;
class USym_UserView;
class UWriter_Master;
class UWriter_AtlasView;
class UWriter_FormView;
class UWriter_VSetup;
class UWriter_VSetupEntry;

class OUNIVERSE_API ClassC
{


public:

	static void Setup();

	static bool IsSetup();
	static TSubclassOf<UCharacterA> F_CharacterA();
	static TSubclassOf<ACharacter3D> F_Character3D();

	static TSubclassOf<UUi>						U_Ui();
	static TSubclassOf<UConsole_Master>			Console_Master();
	static TSubclassOf<ULogv_Master>			Logv_Master();
	static TSubclassOf<UPulse_Master>			Pulse_Master();
	static TSubclassOf<USym_EmptyView>			Sym_EmptyView();
	static TSubclassOf<USym_Master>				Sym_Max();
	static TSubclassOf<USym_UserView>			Sym_UserView();
	static TSubclassOf<UWriter_Master>			Writer_Master();
	static TSubclassOf<UWriter_AtlasView>		Writer_AtlasView();
	static TSubclassOf<UWriter_FormView>		Writer_FormView();
	static TSubclassOf<UWriter_VSetup>			Writer_VSetup();
	static TSubclassOf<UWriter_VSetupEntry>		Writer_VSetupEntry();
};
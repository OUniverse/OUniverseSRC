//Copyright 2015-2019, All Rights Reserved.

//O:\ouniverse\ouniverse\SourceMVS\include

#include "System/Boot.h"
#include "System/Major.h"
#include "System/Log.h"
#include "System/ConfigManager.h"
#include "System/HudUE.h"
#include "System/Ui.h"
#include "System/Maestro.h"
#include "System/InputManager.h"
#include "System/AudioManager.h"
#include "System/ViewportUE.h"
#include "System/ControlUE.h"
#include "Kismet/GameplayStatics.h"
#include "System/Mode.h"
#include "Engine/World.h"
#include "System/Glass.h"
#include "System/OniManager.h"
#include "System/Time.h"
#include "System/TickUE.h"
#include "System/Fps.h"
#include "System/Cosmos.h"
#include "System/Camera.h"

#include "System/User.h"
#include "System/UserDais.h"
#include "System/UserLib.h"
#include "System/Loadout.h"
#include "System/LoadoutDais.h"
#include "System/LoadoutLib.h"
#include "System/Save.h"
#include "System/SaveDais.h"
#include "System/SaveLib.h"
#include "System/SaveVat.h"

#include "System/Data.h"
#include "System/Terra.h"
#include "System/Ether.h"
#include "System/Party.h"


#include "Min/DebugM.h"
#include "System/Log.h"


#include "System/ProgramState.h"


#include "Interface/Url.h"

namespace GlobalVars
{
	EBootMethod BootMethod;
}

namespace GlobalSingleton
{
	BootC gBoot;
}

BootC* BootC::Get()
{
	return &GlobalSingleton::gBoot;
}

BootC* BootC::Create(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	GlobalSingleton::gBoot = *(new BootC(InBootMethod, WorldContextObject));
	return &GlobalSingleton::gBoot;
}

void UBoot::Boot(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	BootC::Create(InBootMethod, WorldContextObject);
}

void UBoot::UiReady()
{
	BootC::Get()->PostUI();
}


BootC::BootC(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	BootMethod_ = InBootMethod;
	GlobalVars::BootMethod = InBootMethod;

	switch (InBootMethod) {
	case EBootMethod::Standard:
		ProgramState_ = ProgramStateC::State::Standard;
		Primal_Standard(WorldContextObject);
		break;
	case EBootMethod::Scribe:
		ProgramState_ = ProgramStateC::State::Scribe;
		Primal_Scribe(WorldContextObject);
		break;
	case EBootMethod::Test:
		ProgramState_ = ProgramStateC::State::Test;
		Primal_Test(WorldContextObject);
		break;
	case EBootMethod::UiIso:
		ProgramState_ = ProgramStateC::State::UiIso;
		Primal_UiIso(WorldContextObject);
		break;
	}
}


void BootC::Primal_Standard(UObject* WorldContextObject)
{
	if (GEngine)
		DBUG("Standard Boot Activated.")


	MajorC::Create();
	MajorC* M = MajorC::Get();

	M->WorldContext_ = WorldContextObject;

	M->Scope_ = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	M->Viewport_ = Cast<UViewportUE>(M->Scope()->GetGameInstance()->GetGameViewportClient());
	
	bool bModeFail = false;
	if (M->Scope()->GetAuthGameMode()->GetClass() != AMode::StaticClass())
	{
		bModeFail = true;
	}
	
	PathC::SetGlobals(); //Must be called to set global paths to reduce the amount of string assembly functions at run time.
	M->Log_ = LogC::Create(PathC::FileLog());

	LOG(10000, Void(), "Standard Boot Activated. MajorC, PathsC, and LogC services have been created.")

		if (bModeFail)
		{
			DBUGC(RGB_ERR, "The game mode is not correct. It should be AMode...")

				LOG(19222, Void(), "The game mode is incorrectly set. It should be AMode. ")

				return;
		}

	M->Oni_ = new OniManagerC();
	M->Oni()->Load(OniTypeC::Type::Internal, PathC::FileInternalConfig());
	M->Oni()->Load(OniTypeC::Type::Global, PathC::FileGlobalConfig());

	//DBUG(M->Oni()->GetSerializedCategory(OniTypeC::Type::Global,1).ToChar())

	M->Config_ = new ConfigManager(M->Oni());

	M->Control_ = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));

	M->Hud_ = Cast<AHudUE>(M->Control()->GetHUD());

	M->Hud()->HUD_SUPER_ON(AHudUE::HudTypes::Standard);

	//M->Audio_ = AudioManager::Create(M->Scope());

	LOGP
}

void BootC::Primal_Scribe(UObject* WorldContextObject)
{
	LOGP
}

void BootC::Primal_UiIso(UObject* WorldContextObject)
{
	LOGP
}

void BootC::Primal_Test(UObject* WorldContextObject)
{
	
}











void BootC::PostUI()
{
	if (ProgramState_ == ProgramStateC::State::Standard)
	{
		PostUI_Standard();
	}
	else if (ProgramState_ == ProgramStateC::State::Scribe)
	{
		PostUI_Scribe();
	}
	else if (ProgramState_ == ProgramStateC::State::UiIso)
	{
		PostUI_UiIso();
	}
}


void BootC::PostUI_Standard()
{

	//DBUG("CUI Ready...");
	//GSEND0("ui.o")

	LOG(40448, Void(), "UI is ready for bindings.")

	MajorC* M = MajorC::Get();


	M->Data_ = DataC::Create(PathC::DirAtlas());


	
	M->Time_ = TimeC::Create();
	M->TickUE_ = NewObject<UTickUE>();
	M->TickUE()->BridgeAndBegin(M->Time());
	
	M->Fps_ = FpsC::Create(M->Time_);

	M->UserDais_ = new UserDaisC(M->Oni());
	M->LoadoutDais_ = new LoadoutDaisC();
	M->SaveDais_ = new SaveDaisC();
	
	M->UserLib_ = new UserLibC(PathC::DirUsers(), M->UserD(), M->Oni());
	M->LoadoutLib_ = new LoadoutLibC(M->LoadoutD(), M->Oni());
	M->SaveLib_ = new SaveLibC(M->SaveD());
	M->SaveV_ = new SaveVatC(M->SaveD());

	M->Input_ = new InputManager(PathC::FileGlobalConfig());

	M->Ui_		= UiC::Create(M);
	M->Maestro_ = MaestroC::Create(M);

	M->Cosmos_ = CosmosC::Create();

	M->Terra_ = TerraC::Create();
	M->Ether_ = EtherC::Create(M->WorldContext(),M->Scope());
	M->Party_ = PartyC::Create();

	M->UserL()->Load();
	M->UserL()->Decide();

	M->Hud()->ActivateInputs(M->Input());

	//M->Maestro()->Start();

	M->Camera_ = new CameraC(M->Ether());
	M->Camera()->Activate(M->Control());
	M->UserL()->Set(32767);
	M->LoadoutL()->Load(M->UserD()->Folder());
	M->LoadoutL()->Set(1314);
	M->Data()->Mount(M->LoadoutD()->Get());

	M->SaveL()->Load(M->UserD()->Folder());	
	M->SaveL()->Set(32767);
	M->SaveV()->Load();

	M->Cosmos()->FauxMount();

	LOGP
}

void BootC::PostUI_Scribe()
{
	LOGP
}

void BootC::PostUI_UiIso()
{
	DBUG("PostUI_UiISO_CUI Ready...");

	LOG(40448, Void(), "UI is ready for bindings.")

		MajorC* M = MajorC::Get();

	//M->Input_ = InputManager::Create(M->Path()->Reg());
	M->Hud()->ActivateInputs(M->Input());

}
//Copyright 2015-2019, All Rights Reserved.

//O:\ouniverse\ouniverse\SourceMVS\include

#include "System/Boot.h"
#include "System/GameInstanceUE.h"
#include "System/Major.h"

#include "Class/ClassGeneral.h"
#include "Class/ClassProtocol.h"
#include "Class/ClassForm.h"

#include "System/Class.h"

#include "System/Babel.h"
#include "System/Log.h"
#include "System/ConfigManager.h"
#include "System/HudUE.h"
#include "System/Maestro.h"
#include "System/AudioManager.h"
#include "System/ViewportUE.h"
#include "System/ControlUE.h"
#include "Kismet/GameplayStatics.h"
#include "System/Mode.h"
#include "Engine/World.h"
#include "System/OniManager.h"
#include "System/Time.h"
#include "System/TickUE.h"
#include "System/Fps.h"
#include "System/Cosmos.h"
#include "System/Scope.h"
#include "Ui/Ui.h"

#include "System/AtlasLib.h"
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


#include "System/Terra.h"

#include "Protocol/ProtocolREG.h"

#include "Min/DebugM.h"
#include "System/Log.h"


#include "System/ProgramState.h"


#include "Interface/Url.h"

#include "Interface/Data.h"

#include "System/Logger.h"


#include "Framework/Application/SlateApplication.h"

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


BootC::BootC(EBootMethod InBootMethod, UObject* WorldContextObject)
{
	BootMethod_ = InBootMethod;
	GlobalVars::BootMethod = InBootMethod;

	switch (InBootMethod) {
	case EBootMethod::Standard:
		Standard(WorldContextObject);
		break;
	}
}


void BootC::Standard(UObject* WorldContextObject)
{

	if (!GEngine)
	{
		DBUG("NO GENGINE.")
			return;
	}
	DBUG("Standard Boot Activated.")

	UObject* WorldContextObject_PRE = WorldContextObject;
	UWorld* Scope_PRE = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	UGameInstanceUE* Singleton = Cast<UGameInstanceUE>(Scope_PRE->GetGameInstance());

	if (!Singleton) 
	{
		DBUG("GameInstance was not set to UGameInstanceUE.")
			return;
	}



	

	UMajor* M = UMajor::Create();
	Singleton->Major_ = M;
	
	M->Scope_ = new ScopeC(WorldContextObject_PRE,Scope_PRE);

	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	M->Viewport_ = Cast<UViewportUE>(ScopeC::World()->GetGameInstance()->GetGameViewportClient());

	bool bModeFail = false;
	if (M->Scope()->World()->GetAuthGameMode()->GetClass() != AMode::StaticClass())
	{
		bModeFail = true;
	}

	UClassGeneral::Initialize();
	UClassProtocol::Initialize();

	ClassC::Setup();
	if (!ClassC::IsSetup())
	{
		DBUG("ClassC was not setup properly.")
			return;
	}

	PathC::SetGlobals(); //Must be called to set global paths to reduce the amount of string assembly functions at run time.
	
	
	
	M->Logger_ = LoggerC::Create(PathC::FileLogLegend(), PathC::FileLog());
	M->Log_ = LogC::Create(PathC::FileLog());


	
	LOGGER("Begin standard boot.", LoggerEntryC::W(37524)->Mail())

		if (bModeFail)
		{
			//Error here happens if the main map's mode is not AMode.
			DBUGC(RGB_ERR, "The game mode is not correct. It should be AMode...")
			LOGGER("The game mode is incorrectly set.",LoggerEntryC::W(19595)->Mail())
	
			return;
		}

	M->Babel_ = BabelC::Create(PathC::FileBabel());

	M->Oni_ = new OniManagerC();
	M->Oni()->Load(OniTypeC::Type::Internal, PathC::FileInternalConfig());
	M->Oni()->Load(OniTypeC::Type::Global, PathC::FileGlobalConfig());

	//DBUG(M->Oni()->GetSerializedCategory(OniTypeC::Type::Global,1).ToChar())

	M->Config_ = new ConfigManager(M->Oni());

	M->Control_ = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));

	M->Hud_ = Cast<AHudUE>(M->Control()->GetHUD());

	//M->Audio_ = AudioManager::Create(M->Scope());




	M->Time_	= TimeC::Create();
	M->TickUE_	= NewObject<UTickUE>();
	M->TickUE()->BridgeAndBegin(M->Time());

	M->Fps_ = FpsC::Create(M->Time_);

	M->LoadoutDais_ = new LoadoutDaisC();
	M->UserDais_ = new UserDaisC(M->Oni());
	M->SaveDais_ = new SaveDaisC();
	M->UserLib_ = new UserLibC(PathC::DirUsers(), M->UserD(), M->Oni());
	M->LoadoutLib_ = new LoadoutLibC(M->LoadoutD(), M->Oni());
	M->SaveLib_ = new SaveLibC(M->SaveD());
	M->SaveV_ = new SaveVatC(M->SaveD());

	M->UserD()->Initialize(M->LoadoutL());
	M->UserL()->Load();
	
	M->Atlas_ = AtlasLibC::Create(PathC::DirAtlas(),M->LoadoutD());

	M->Ui_ = UUi::Create();

	M->Cosmos_ = UCosmos::Create(M->Control());

	M->Camera_ = M->Cosmos()->SpawnCamera();
	M->Control()->SetCamera(M->Camera());
	
	M->Terra_ = TerraC::Create();


	








	M->Maestro_ = MaestroC::Create();
	M->Maestro()->Initialize(M);

	M->Control()->Init(M->Maestro());
	

	//M->UserL()->Set(32767);
	//M->LoadoutL()->Load(M->UserD()->Folder());
	//M->LoadoutL()->Set(1314);
	//M->Atlas()->Mount(M->LoadoutD()->Get());

	//M->SaveL()->Load(M->UserD()->Folder());
	//M->SaveL()->Set(32767);
	//M->SaveV()->Load();


	//M->Maestro()->FauxStart();
	//M->Maestro()->WriterStart();

	M->Maestro()->Start();

	LOGGER("Standard Boot Complete.", LoggerEntryC::W(39464)->Mail())
}
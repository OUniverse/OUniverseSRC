//Copyright 2015-2019, All Rights Reserved.

//O:\ouniverse\ouniverse\SourceMVS\include

#include "System/Boot.h"
#include "System/Major.h"
#include "System/Paths.h"
#include "System/Log.h"
#include "System/Kernel.h"
#include "System/ConfigManager.h"
#include "System/UserLib.h"
#include "System/HudUE.h"
#include "System/SystemManager.h"
#include "System/UiManager.h"
#include "System/ProtocolManager.h"
#include "System/InputManager.h"
#include "System/AudioManager.h"
#include "System/ViewportUE.h"
#include "System/ControlUE.h"
#include "Kismet/GameplayStatics.h"
#include "System/Mode.h"
#include "Engine/World.h"
#include "System/Glass.h"

#include "System/Data.h"
#include "System/Terra.h"

#include "Interface/Dir.h"
#include "Min/DebugM.h"
#include "System/Log.h"

#include "Ui/Ui.h"


namespace GlobalVars
{
	EBootMethod BootMethod;
}

void UBoot::Boot(EBootMethod BootMethod, UObject* WorldContextObject)
{
	GlobalVars::BootMethod = BootMethod;

	switch (BootMethod) {
	case EBootMethod::Standard:
		StandardBoot(WorldContextObject);
		break;
	case EBootMethod::Test:
		TestBoot(WorldContextObject);
		break;
	case EBootMethod::UiIso:
		UiIsoBoot(WorldContextObject);
		break;
	case EBootMethod::Scribe:
		StandardBoot(WorldContextObject);
		break;
	}
}


void UBoot::StandardBoot(UObject* WorldContextObject)
{
	if (GEngine)
		DBUG("Standard Boot Activated.")


	MajorC::Create();
	MajorC* M = MajorC::Get();

	M->Scope_ = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	M->Viewport_ = Cast<UViewportUE>(M->Scope()->GetGameInstance()->GetGameViewportClient());

	bool bModeFail = false;
	if (M->Scope()->GetAuthGameMode()->GetClass() != AMode::StaticClass())
	{
		bModeFail = true;
	}


	M->Path_ = PathsC::Create();
	M->Log_ = LogC::Create(M->Path()->Logs());

	LOG(10000, Void(), "Standard Boot Activated. MajorC, PathsC, and LogC services have been created.")

		if (bModeFail)
		{
			DBUGC(RGB_ERR, "The game mode is not correct. It should be AMode...")

				LOG(19222, Void(), "The game mode is incorrectly set. It should be AMode. ")

				return;
		}

	M->Config_ = ConfigManager::Create(M->Path()->Config(), M->Path()->ActiveUser());
	LOG(28164, Void(), "ConfigC service activated.")

		M->Control_ = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));

	M->Hud_ = Cast<AHudUE>(M->Control()->GetHUD());

	M->Hud()->PrepareInputs(false,"");

	//M->Audio_ = AudioManager::Create(M->Scope());


	//Ui* UiTest = new Ui();
	//UiTest->Activate();
	//GlassC::SetView("curl://ui/ui.html");

	LOGP
}

void UBoot::UiReady()
{

	//DBUG("CUI Ready...");
	//GSEND0("ui.o")

	LOG(40448, Void(), "UI is ready for bindings.")

		MajorC* M = MajorC::Get();

	M->Data_ = DataC::Create(M->Path()->Atlas()->Get());
	M->Kernel_ = KernelC::Create(M->Data());

	M->UserLib_ = UserLibC::Create(M->Path()->Users(), M->Kernel());


	M->System_ = SystemManager::Create();
	M->Input_ = InputManager::Create(M->Path()->Reg());
	//M->Ui_		= UiManager::Create(M->Hud()->GetGlass());
	M->Protocol_ = ProtocolManager::Create(M);

	M->Terra_ = TerraC::Create();

	M->UserL()->LoadUsers();

	M->Hud()->ActivateInputs(M->Input());

	if (GlobalVars::BootMethod != EBootMethod::Scribe)
	{
		M->Protocol()->Activate(ProtocolManager::Types::System);
	}
	else
	{
		M->Protocol()->Activate(ProtocolManager::Types::Scribe);
	}
	LOGP
}




void UBoot::TestBoot(UObject* WorldContextObject)
{

}






void UBoot::UiIsoBoot(UObject* WorldContextObject)
{
	if (GEngine)
		//DBUG("Standard Boot Activated.")


	MajorC::Create();
	MajorC* M = MajorC::Get();

	M->Scope_ = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	M->Viewport_ = Cast<UViewportUE>(M->Scope()->GetGameInstance()->GetGameViewportClient());

	bool bModeFail = false;
	if (M->Scope()->GetAuthGameMode()->GetClass() != AMode::StaticClass())
	{
		bModeFail = true;
	}


	M->Path_ = PathsC::Create();
	M->Log_ = LogC::Create(M->Path()->Logs());

	LOG(10000, Void(), "Standard Boot Activated. MajorC, PathsC, and LogC services have been created.")

		if (bModeFail)
		{
			DBUGC(RGB_ERR, "The game mode is not correct. It should be AMode...")

				LOG(19222, Void(), "The game mode is incorrectly set. It should be AMode. ")

				return;
		}

	M->Config_ = ConfigManager::Create(M->Path()->Config(), M->Path()->ActiveUser());
	LOG(28164, Void(), "ConfigC service activated.")

	M->Control_ = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));

	M->Hud_ = Cast<AHudUE>(M->Control()->GetHUD());

	M->Hud()->PrepareInputs(true, "coui://ui//scribe.html");

	LOGP
}

void UBoot::UiReadyIsoBoot()
{

	//DBUG("CUI Ready...");

	LOG(40448, Void(), "UI is ready for bindings.")

		MajorC* M = MajorC::Get();

	M->Input_ = InputManager::Create(M->Path()->Reg());
	M->Hud()->ActivateInputs(M->Input());

	LOGP
}
//Copyright 2015-2019, All Rights Reserved.

//O:\ouniverse\ouniverse\SourceMVS\include

#include "System/Boot.h"
#include "System/Major.h"
#include "System/Paths.h"
#include "System/Log.h"
#include "System/ConfigManager.h"
#include "System/UserLib.h"
#include "System/HudUE.h"
#include "System/SystemManager.h"
#include "System/UiManager.h"
#include "System/StateManager.h"
#include "System/InputManager.h"
#include "System/AudioManager.h"
#include "System/ViewportUE.h"
#include "System/ControlUE.h"
#include "Kismet/GameplayStatics.h"
#include "System/Mode.h"
#include "Engine/World.h"
#include "Form/Payload.h"

#include "Interface/Dir.h"
#include "Min/DebugM.h"
#include "Min/LogM.h"

void UBoot::Boot(UObject* WorldContextObject)
{
	if (GEngine)
	DBUG("Standard Boot Activated.")


	MajorC::Create();
	MajorC* M = MajorC::Get();

	M->Scope_ = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	M->Viewport_ = Cast<UViewportUE>(M->Scope()->GetGameInstance()->GetGameViewportClient());

	bool bModeFail = false;
	if(M->Scope()->GetAuthGameMode()->GetClass()!=AMode::StaticClass())
	{
		bModeFail = true;
	}

	
	M->Path_	= PathsC::Create();
	M->Log_		= LogC::Create(M->Path()->Logs());

	//M->Config_ = ConfigManager::Create(M->Path()->Users*, M->Path()->ActiveUser*);

	LOG(BOOT, 0, 0, "Standard Boot... ^")
	LOG(BOOT, 0, 0, "Major Created ^")
	LOG(BOOT, 0, 0, "Path Created ^")
	LOG(BOOT, 0, 0, "Log Created")
	LOGP

	if (bModeFail)
	{
		DBUGC(RGB_ERR, "The game mode is not correct. It should be AMode...")
		LOGD(BOOT, 0, 0, "ERROR: The game mode is not correct. It should be AMode...")
		return;
	}

	M->Config_ = ConfigManager::Create(M->Path()->Config(), M->Path()->ActiveUser());
	LOG(BOOT, 0, 0, "Config Created")

	
	M->User_	= UserLib::Create(M->Path()->Users());

	M->Control_ = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));
	
	M->Hud_ = Cast<AHudUE>(M->Control()->GetHUD());

	M->User()->LoadUsers();
	M->User()->SetUser(65535);

	//M->Hud()->PrepareInputs(M->Path()->UiServer());

	//M->Audio_ = AudioManager::Create(M->Scope());
	
	LOGP
	DBUG("Waiting for CUI...")
}

#include "Interface/File.h"

void UBoot::TestBoot(UObject* WorldContextObject)
{
	DBUG("Test Boot Activated.");
	MajorC::Create();
	MajorC* M = MajorC::Get();
	M->Test1();
	
	M->Path_ = PathsC::Create();
	M->Log_ = LogC::Create(M->Path()->Logs());

	LOG(BOOT, 0, 0, "Standard Boot... ^")
		LOG(BOOT, 0, 0, "Major Created ^")
		LOG(BOOT, 0, 0, "Path Created ^")
		LOG(BOOT, 0, 0, "Log Created")
		LOGP


	M->Config_ = ConfigManager::Create(M->Path()->Config(), M->Path()->ActiveUser());

	//FileReadS FileReader = FileReadS(TCHAR_TO_ANSI(*(M->Path()->Content() + "test.txt")));
	//DBUG("OK");

	//FileC::Empty(M->Path()->Content() + "test2.txt");

	//FileC::Append(TCHAR_TO_ANSI(*(M->Path()->Content() + "test2.txt")), FileReader.AsFString());
	
	//FileC::Delete(M->Path()->DContent() + "test2.txt");

	//new PayloadC(TCHAR_TO_ANSI(*(PathsC::Create()->DContent() + "testfolder/")));
}

void UBoot::CoherentReady()
{
	DBUG("CUI Ready...");

	MajorC* M	= MajorC::Get();
	M->System_	= SystemManager::Create();
	M->Input_	= InputManager::Create(M->Hud()->GetUi(), M->Hud()->GetNativeUiInput(), M->Path()->Reg());
	M->Ui_		= UiManager::Create(M->Hud()->GetUi());
	M->State_	= StateManager::Create();
}
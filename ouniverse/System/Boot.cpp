//Copyright 2015-2019, All Rights Reserved.

//O:\ouniverse\ouniverse\SourceMVS\include

#include "System/Boot.h"
#include "System/Major.h"
#include "System/Paths.h"
#include "System/Log.h"
#include "System/ConfigManager.h"
#include "System/UserManager.h"
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

#include "Min/DebugM.h"

void UBoot::Boot(UObject* WorldContextObject)
{
	if (GEngine)
	DBUG("Standard Boot Activated.");

	MajorC::Create();
	MajorC* M = MajorC::Get();

	M->Scope_ = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	//A crash here means that the custom ViewportClient is no longer set correctly in UE4.
	M->Viewport_ = Cast<UViewportUE>(M->Scope()->GetGameInstance()->GetGameViewportClient());

	if(M->Scope()->GetAuthGameMode()->GetClass()!=AMode::StaticClass())
	{
		DBUGC(RGB_ERR,"The game mode is not set to the correct class. Should be AMode...");
		return;
	}

	M->Path_	= PathsC::Create();
	M->Log_		= LogC::Create(M->Path()->DGlobalLogs());
	M->Config_	= ConfigManager::Create(M->Path()->DUsers(),"FIXTHIS");
	M->User_	= UserManager::Create(M->Config(),NULL);

	M->Control_ = Cast<AControlUE>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));
	
	M->Hud_ = Cast<AHudUE>(M->Control()->GetHUD());
	M->Hud()->PrepareInputs(M->Path()->DUiServer());

	M->Audio_ = AudioManager::Create(M->Scope());
	
	DBUG("Waiting for CUI...");
}


void UBoot::TestBoot(UObject* WorldContextObject)
{
	DBUG("Test Boot Activated.");
	MajorC::Create();
	MajorC* M = MajorC::Get();
	M->Test1();
	//new PayloadC(TCHAR_TO_ANSI(*(PathsC::Create()->DContent() + "testfolder/")));
}

void UBoot::CoherentReady()
{
	DBUG("CUI Ready...");

	MajorC* M	= MajorC::Get();
	M->System_	= SystemManager::Create();
	M->Input_	= InputManager::Create(M->Hud()->GetUi(), M->Hud()->GetNativeUiInput(), M->Path()->DContentReg());
	M->Ui_		= UiManager::Create(M->Hud()->GetUi());
	M->State_	= StateManager::Create();
}
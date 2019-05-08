//Copyright 2015-2019, All Rights Reserved.



#include "System/Boot.h"
#include "System/Major.h"
#include "System/PathManager.h"
#include "System/Log.h"
#include "System/ConfigManager.h"
#include "System/UserManager.h"
#include "System/DisplayManager.h"
#include "System/SystemManager.h"
#include "System/UiManager.h"
#include "System/StateManager.h"
#include "System/InputManager.h"
#include "System/AudioManager.h"
#include "System/ViewportClient.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/WorldSettings.h"
#include "System/Mode.h"
#include "Engine/World.h"
#include "Form/Payload.h"

void UBoot::Boot(UObject* WorldContextObject)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("We have booted!"));

	Major::Create();
	Major* M = Major::Get();

	M->Scope_ = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	//If Major (this) is returning as nullptr it means this specialty GameViewPortClient class got removed from the Editor Project Settings as default.
	M->Viewport_ = Cast<UViewportClient>(M->Scope()->GetGameInstance()->GetGameViewportClient());


	//Make sure the gamemode is correct. If not post a message so it's clear.
	if(M->Scope()->GetAuthGameMode()->GetClass()!=AMode::StaticClass())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("The game mode is not set to the correct class. Should be AMode..."));
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz!"));

	M->Path_	= PathManager::Create();
	M->Log_		= LogC::Create(M->Path()->DGlobalLogs());
	M->Config_	= ConfigManager::Create(M->Path()->DUsers(),"FIXTHIS");
	M->User_	= UserManager::Create(M->Config(),NULL);

	M->Control_ = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	
	//AWorldSettings* WorldSettings = M->Scope()->GetWorldSettings();
	//WorldSettings->DefaultGameMode = AMode::StaticClass();

	//AddLog(ELog::Primary, UDU_GlobalLogsPath + FString(LOG_NAME_PRIMARY));

	M->Display_ = Cast<ADisplayManager>(M->Control()->GetHUD());
	M->Display()->PrepareInputs(M->Path()->DUiServer());

	M->Audio_ = AudioManager::Create(M->Scope());
	
	//DEBUGPRINT(FColor::Turquoise, "Major Boot()...");
}

void UBoot::TestBoot(UObject* WorldContextObject)
{
	new Payload(TCHAR_TO_ANSI(*(PathManager::Create()->DContent() + "testfolder/")));
}

void UBoot::CoherentReady()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("COHERENT READY"));

	Major* M	= Major::Get();
	M->System_	= SystemManager::Create();
	M->Input_	= InputManager::Create(M->Display()->GetUi(), M->Display()->GetNativeUiInput(), M->Path()->DContentReg());
	M->Ui_		= UiManager::Create(M->Display()->GetUi());
	M->State_	= StateManager::Create();
}
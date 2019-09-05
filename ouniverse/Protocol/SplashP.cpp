//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/SplashP.h"

#include "System/Maestro.h"
#include "System/Glass.h"

#include "Min/DebugM.h"

SplashP::SplashP(MaestroC* InMaestro, InputManager* InInputManager)
{
	Input_ = InInputManager;
	Maestro_ = InMaestro;
}

void SplashP::Activate()
{
	CommandE Event = Input_->ListenToCMD(InputManager::Layer::Menu, CommandLayerMenuC::CMD::Enter);
	CMD_Enter = *Event->Bind(Event->Create(this, &SplashP::OnSkip));

	Event = Input_->ListenToCMD(InputManager::Layer::Menu, CommandLayerMenuC::CMD::Escape);
	CMD_Enter = *Event->Bind(Event->Create(this, &SplashP::OnSkip));
	
	Event = Input_->ListenToCMD(InputManager::Layer::Menu, CommandLayerMenuC::CMD::Space);
	CMD_Enter = *Event->Bind(Event->Create(this, &SplashP::OnSkip));

	CurrentStage_ = Stage::Brander;

	GSEND0("splash+");
	GSEND0("splash.brand");

	GBIND("splash.click", this, &SplashP::OnClick);
}


void SplashP::OnClick()
{
	Skip();	
}

void SplashP::Skip()
{
	if (CurrentStage_ == Stage::Brander)
	{
		CurrentStage_ = Stage::Sponsor;
		GSEND0("splash.sponsor");
	}
	else if (CurrentStage_ == Stage::Sponsor)
	{
		CurrentStage_ = Stage::Intro;
		GSEND0("splash.intro");
	}
	else if (CurrentStage_ == Stage::Intro)
	{
		GSEND0("splash-");
		Maestro_->SplashEnd();
	}
}
void SplashP::OnSkip(StrokeS InStroke)
{

	if (InStroke.KeyDown())
	{
		Skip();
	}
}
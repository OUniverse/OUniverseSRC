//Copyright 2015-2019, All Rights Reserved.

#include "System/Glass.h"
#include "System/HudUE.h"



namespace GlassGlobals
{
	GlassC Glass;
}

GlassC::GlassC(AHudUE* InHud)
{
	Hud_ = InHud;
}

GlassC* GlassC::Get()
{
	return &GlassGlobals::Glass;
}

GlassC* GlassC::Create(AHudUE* InHud)
{
	GlassGlobals::Glass = *(new GlassC(InHud));
	return &GlassGlobals::Glass;
}

TSharedPtr<class SCohtmlInputForward> GlassC::Bridge()
{
	return GlassGlobals::Glass.Hud_->CoBridge_;
}

coview GlassC::View()
{
	return GlassGlobals::Glass.Hud_->CoHud_->GetView();
}

AHudUE* GlassC::Hud()
{
	return GlassGlobals::Glass.Hud_;
}

void GlassC::SetView(const char* InURL)
{
	GlassGlobals::Glass.Hud_->SetView(InURL);
}



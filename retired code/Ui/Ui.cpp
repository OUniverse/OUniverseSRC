//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui.h"
#include "System/HudUE.h"
#include "System/Glass.h"
#include "System/Paths.h"
#include "Interface/String.h"
#include "CohtmlInputActor.h"
#include "System/Boot.h"

Ui::Ui()
{

}

const char* Ui::Path()
{
	return "coui://ui//sym.html";
}

void Ui::Activate()
{
	GlassC::Hud()->SetView(Path());
	Event0C<EventLife>::Listener0C* NewListener = GlassC::Hud()->OnViewReady_.Create(this,&Ui::ViewReady);
	NewListener->Bind();

	//yForBindings.AddDynamic(this, &Ui::ViewReady);
}

EventLife Ui::ViewReady()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "THIS HAS WORKED NOW!");
	UBoot::UiReady();
	return EventLife(false);
}
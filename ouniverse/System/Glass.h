//Copyright 2015-2019, All Rights Reserved.

/**

## Glass

Glass is a bridge / interface wrapper between the UI and the game code.
* Created once in the boot process.

> Currently it's a bridge between C++ to Coherent Labs UI system and is interacting with Javascript there.

**Creator:** AHudUE Outputs this to UBoot
**Holder:** Major

*/

#pragma once

#include "cohtml/View.h"
#include "CohtmlHUD.h"
#include "SCohtmlInputForward.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"

typedef cohtml::View* coview;
class AHudUE;

class GlassC
{

	friend AHudUE;

private:

	static GlassC* Create(AHudUE* InHud);

public:

	GlassC() {};
	GlassC(AHudUE* InHud);

	static GlassC* Get();

	static TSharedPtr<class SCohtmlInputForward> Bridge();

	static coview View();

	static AHudUE* Hud();

	static void SetView(const char* InURL);

private:

	AHudUE* Hud_;
};



#define GBIND(EventName, Object, Method) GlassC::Get()->View()->BindCall(EventName, cohtml::MakeHandler(Object, Method));
#define GSEND0(EventName) GlassC::Get()->View()->TriggerEvent(EventName);
#define GSEND1(EventName,P1) GlassC::Get()->View()->TriggerEvent(EventName,P1);
#define GSEND2(EventName,P1,P2) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2);
#define GSEND3(EventName,P1,P2,P3) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2,P3);
#define GSEND4(EventName,P1,P2,P3,P4,P5) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2,P3,P4);
#define GSEND5(EventName,P1,P2,P3,P4,P5) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2,P3,P4,P5);

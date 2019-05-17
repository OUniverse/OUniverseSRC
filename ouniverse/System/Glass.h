//Copyright 2015-2019, All Rights Reserved.

/**
Glass is a bridge / interface wrapper between the UI and the game code.
Currently it's a bridge between C++ to Coherent Labs UI system and is interacting with Javascript there.
*/

#pragma once

#include "CoreMinimal.h"
#include "Interface/String.h"
#include "Interface/Array.h"

#include "cohtml/View.h"
#include "CohtmlHUD.h"
#include "SCohtmlInputForward.h"

typedef cohtml::View* coview;
class AHudUE;

class GlassC
{

	friend AHudUE;

private:

	static GlassC* Create();

public:

	GlassC();

	static GlassC* Get();

	TSharedPtr<class SCohtmlInputForward> Native();

	coview View();

private:

	UCohtmlHUD* Ui_;

	TSharedPtr<class SCohtmlInputForward> NativeInput_;

};

#define GBIND(EventName, Object, Method) GlassC::Get()->View()->BindCall(EventName, cohtml::MakeHandler(Object, Method));
#define GSEND0(EventName) GlassC::Get()->View()->TriggerEvent(EventName);
#define GSEND1(EventName,P1) GlassC::Get()->View()->TriggerEvent(EventName,P1);
#define GSEND2(EventName,P1,P2) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2);
#define GSEND3(EventName,P1,P2,P3) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2,P3);
#define GSEND4(EventName,P1,P2,P3,P4,P5) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2,P3,P4);
#define GSEND5(EventName,P1,P2,P3,P4,P5) GlassC::Get()->View()->TriggerEvent(EventName,P1,P2,P3,P4,P5);

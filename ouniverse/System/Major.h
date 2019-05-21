//Copyright 2015-2019, All Rights Reserved.

/**

## Major
> **Service Locator: Created once only by the boot process.**

> **Accessed through a Minimal Macro Wrapper MajorM.**

A service locator singleton that holds the pointers to all the services.

*Major will be sparingly dropped in locations where Dependency Injection is causing too much pressure and not logically feeling great. Generally if parameters are being passed around only to hand off with no relevance to the receiver it will be omitted from injection and retrieved when needed from Major.*

**Creator:** UBoot
**Holder:** GlobalSingletons namespace as a global var

 */

#pragma once

#include "CoreMinimal.h"
#include "Min/HttpM.h"
#include "Interface/Event.h"

class LogC;
class PathsC;
class DataC;
class CosmosC;
class TerraC;
class KernelC;
class UserLib;
class SessionLib;
class InputManager;
class DisplayManager;
class ConfigManager;
class UiManager;
class InputManager;
class AudioManager;
class StateManager;
class AudioManager;
class UViewportUE;
class AHudUE;
class AControlUE;
class SystemManager;


class UBoot;


class OUNIVERSE_API MajorC
{
	friend UBoot;

public:

	MajorC() {};
	static MajorC* Get();
	static MajorC* Create();

	LogC*			Log();
	PathsC*			Path();
	UserLib*		UserL();
	ConfigManager*	Config();
	SystemManager*	System();
	InputManager*	Input();
	AudioManager*	Audio();
	AControlUE*		Control();
	UiManager*		Ui();
	StateManager*	State();
	AHudUE*			Hud();
	UWorld*			Scope();
	UViewportUE*	Viewport();
	DataC*			Data();
	CosmosC*		Cosmos();
	TerraC*			Terra();
	KernelC*		Kernel();

private:

	LogC*			Log_;
	PathsC*			Path_;
	UserLib*		UserLib_;
	ConfigManager*	Config_;
	UiManager*		Ui_;
	StateManager*	State_;
	SystemManager*	System_;
	AudioManager*	Audio_;
	InputManager*	Input_;
	UWorld*			Scope_;
	UViewportUE*	Viewport_;
	AHudUE*			Hud_;
	AControlUE*		Control_;
	DataC*			Data_;
	CosmosC*		Cosmos_;
	TerraC*			Terra_;
	KernelC*		Kernel_;
};
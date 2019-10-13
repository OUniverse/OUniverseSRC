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


class UserW;
class UserLibC;
class LoadoutW;
class LoadoutLibC;
class SaveW;
class SaveLibC;
class LogC;
class DataC;
class TerraC;
class TimeC;
class InputManager;
class DisplayManager;
class ConfigManager;
class UiManager;
class InputManager;
class AudioManager;
class MaestroC;
class AudioManager;
class UViewportUE;
class AHudUE;
class OniManagerC;
class AControlUE;
class UTickUE;

class BootC;


class OUNIVERSE_API MajorC
{
	friend BootC;

public:

	MajorC() {};
	static MajorC* Get();
	static MajorC* Create();

	UserW*				User();
	UserLibC*			UserL();
	LoadoutW*			Loadout();
	LoadoutLibC*		LoadoutL();
	SaveW*				Save();
	SaveLibC*			SaveL();
	LogC*				Log();
	ConfigManager*		Config();
	InputManager*		Input();
	AudioManager*		Audio();
	AControlUE*			Control();
	UiManager*			Ui();
	MaestroC*			Maestro();
	AHudUE*				Hud();
	UWorld*				Scope();
	UViewportUE*		Viewport();
	OniManagerC*		Oni();
	DataC*				Data();
	TerraC*				Terra();
	TimeC*				Time();
	UTickUE*			TickUE();

private:

	UserW*				UserW_;
	UserLibC*			UserLib_;
	LoadoutW*			LoadoutW_;
	LoadoutLibC*		LoadoutLib_;
	SaveW*				SaveW_;
	SaveLibC*			SaveLib_;
	LogC*				Log_;
	ConfigManager*		Config_;
	UiManager*			Ui_;
	MaestroC*			Maestro_;
	AudioManager*		Audio_;
	InputManager*		Input_;
	UWorld*				Scope_;
	UViewportUE*		Viewport_;
	AHudUE*				Hud_;
	AControlUE*			Control_;
	OniManagerC*		Oni_;
	DataC*				Data_;
	TerraC*				Terra_;
	TimeC*				Time_;
	UTickUE*			TickUE_;
};
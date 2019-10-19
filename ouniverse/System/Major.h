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


class UserDaisC;
class UserLibC;
class LoadoutDaisC;
class LoadoutLibC;
class SaveDaisC;
class SaveLibC;
class LogC;
class DataC;
class TerraC;
class TimeC;
class InputManager;
class DisplayManager;
class ConfigManager;
class UiC;
class InputManager;
class AudioManager;
class MaestroC;
class AudioManager;
class UViewportUE;
class AHudUE;
class OniManagerC;
class AControlUE;
class UTickUE;
class FpsC;
class CosmosC;
class EtherC;
class PartyC;
class SaveVatC;
class CameraC;

class BootC;


class OUNIVERSE_API MajorC
{
	friend BootC;

public:

	MajorC() {};
	static MajorC* Get();
	static MajorC* Create();

	UObject*			WorldContext();
	UserDaisC*			UserD();
	UserLibC*			UserL();
	LoadoutDaisC*		LoadoutD();
	LoadoutLibC*		LoadoutL();
	SaveDaisC*			SaveD();
	SaveLibC*			SaveL();
	LogC*				Log();
	ConfigManager*		Config();
	CameraC*			Camera();
	InputManager*		Input();
	AudioManager*		Audio();
	AControlUE*			Control();
	UiC*				Ui();
	MaestroC*			Maestro();
	AHudUE*				Hud();
	UWorld*				Scope();
	UViewportUE*		Viewport();
	OniManagerC*		Oni();
	DataC*				Data();
	TerraC*				Terra();
	TimeC*				Time();
	UTickUE*			TickUE();
	FpsC*				Fps();
	CosmosC*			Cosmos();
	EtherC*				Ether();
	PartyC*				Party();
	SaveVatC*			SaveV();

private:

	UObject*			WorldContext_;
	UserDaisC*			UserDais_;
	UserLibC*			UserLib_;
	CameraC* 			Camera_;
	LoadoutDaisC*		LoadoutDais_;
	LoadoutLibC*		LoadoutLib_;
	SaveDaisC*			SaveDais_;
	SaveLibC*			SaveLib_;
	LogC*				Log_;
	ConfigManager*		Config_;
	UiC*				Ui_;
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
	FpsC*				Fps_;
	CosmosC*			Cosmos_;
	EtherC*				Ether_;
	PartyC*				Party_;
	SaveVatC*			SaveV_;
};
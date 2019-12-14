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
#include "UObject/NoExportTypes.h"
#include "Major.generated.h"

class UserDaisC;
class UserLibC;
class LoadoutDaisC;
class LoadoutLibC;
class SaveDaisC;
class SaveLibC;
class LogC;
class LoggerC;
class AtlasLibC;
class ScopeC;
class BabelC;
class TerraC;
class TimeC;
class ConfigManager;
class UUi;
class AudioManager;
class MaestroC;
class AudioManager;
class UViewportUE;
class AHudUE;
class OniManagerC;
class AControlUE;
class UTickUE;
class FpsC;
class UCosmos;
class SaveVatC;
class ACameraUE;
class BootC;


UCLASS()
class OUNIVERSE_API UMajor : public UObject
{
	GENERATED_BODY()

	friend BootC;

public:

	UMajor() {};
	static UMajor* Get();
	static UMajor* Create();

	UObject*			WorldContext();
	UserDaisC*			UserD();
	UserLibC*			UserL();
	LoadoutDaisC*		LoadoutD();
	LoadoutLibC*		LoadoutL();
	SaveDaisC*			SaveD();
	SaveLibC*			SaveL();
	LogC*				Log();
	LoggerC*			Logger();
	ConfigManager*		Config();
	ACameraUE*			Camera();
	AudioManager*		Audio();
	AControlUE*			Control();
	UUi*				Ui();
	MaestroC*			Maestro();
	AHudUE*				Hud();
	ScopeC*				Scope();
	UViewportUE*		Viewport();
	OniManagerC*		Oni();
	AtlasLibC*			Atlas();
	TerraC*				Terra();
	TimeC*				Time();
	UTickUE*			TickUE();
	FpsC*				Fps();
	UCosmos*			Cosmos();
	SaveVatC*			SaveV();
	BabelC*				Babel();

private:

	UObject*			WorldContext_;
	UserDaisC*			UserDais_;
	UserLibC*			UserLib_;
	ACameraUE* 			Camera_;
	LoadoutDaisC*		LoadoutDais_;
	LoadoutLibC*		LoadoutLib_;
	SaveDaisC*			SaveDais_;
	SaveLibC*			SaveLib_;
	LogC*				Log_;
	LoggerC*			Logger_;
	ConfigManager*		Config_;
	UPROPERTY()
	UUi*				Ui_;
	MaestroC*			Maestro_;
	BabelC*				Babel_;
	AudioManager*		Audio_;
	ScopeC*				Scope_;
	UViewportUE*		Viewport_;
	AHudUE*				Hud_;
	AControlUE*			Control_;
	OniManagerC*		Oni_;
	AtlasLibC*			Atlas_;
	TerraC*				Terra_;
	TimeC*				Time_;
	UTickUE*			TickUE_;
	FpsC*				Fps_;
	UPROPERTY()
	UCosmos*			Cosmos_;
	SaveVatC*			SaveV_;
};
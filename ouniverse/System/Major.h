//Copyright 2015-2019, All Rights Reserved.

/**
Major is a Service Locator singleton and also holds the only memory pointers to the system's services.

Major will be sparingly dropped in locations where Dependency Injection is causing to much pressure and not logically feeling great.
Generally if parameters are being passed around only to hand off with no relevance to the receiver it will be omitted from injection and retrieved when needed from Major.

Major will not be passed through constructors and will instead be reached by a Global Get() from a Macro wrapper minimal script.
 */

#pragma once

#include "CoreMinimal.h"
#include "Min/HttpM.h"
#include "Interface/Event.h"

class LogC;
class PathsC;
class DataC;
class CosmosC;
class UserLib;
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
	UserLib*		User();
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

private:

	LogC*			Log_;
	PathsC*			Path_;
	UserLib*		User_;
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
};
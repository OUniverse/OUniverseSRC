//Copyright 2015-2019, All Rights Reserved.

/**
Major is intended to be the only singleton in use. It's a Service Locator setup however at this point I plan on only using it as a global and not pass it around.
Any case where it could be passed I'll prefer Dependency Injection and call down Major only at certain key points in object chains.

Major will be sparingly dropped in locations where Dependency Injection is causing to much pressure and not logically feeling great.
Certain deep end points might also use it to gain abstract to some of the more abstract systems that don't make sense to hand down many times.

An example of this is the individual UI windows which all need to be tied in to very speicifc things across the program. I will give the UiManager
it's own version of Major so it can distrubte what it needs instead of passing all the services directly to UiManager.

Depenency Injection is greatly prefered unless to many unrelated things are being passed around to reach a distance usage.

Major is mainly allowed when the usage of the program is intangible in an Object Oriented Sense as the program is shifting through an aspect
an example of this is the difference between the boot up process / system menu or in the open world.

In a few cases it will be used in very long Injection chains when Object Oriented Program is simulating to much of the complexity.

A majority of the e
 */

#pragma once

#include "CoreMinimal.h"


class LogC;
class PathManager;
class UserManager;
class InputManager;
class DisplayManager;
class ConfigManager;
class UiManager;
class InputManager;
class AudioManager;
class StateManager;
class AudioManager;
class UViewportClient;
class ADisplayManager;
class APlayerController;
class SystemManager;

class UBoot;

#define MAJOR_IN_USAGE
#define MAJOR MajorC::Get()

class OUNIVERSE_API MajorC
{
	friend UBoot;

public:

	MajorC() {};
	static MajorC* Get();
	static MajorC* Create();

	LogC*				Log();
	PathManager*		Path();
	UserManager*		User();
	ConfigManager*		Config();
	SystemManager*		System();
	InputManager*		Input();
	AudioManager*		Audio();
	APlayerController*	Control();
	UiManager*			Ui();
	StateManager*		State();
	ADisplayManager*	Display();
	UWorld*				Scope();
	UViewportClient*	Viewport();

private:

	LogC*				Log_;
	PathManager*		Path_;
	UserManager*		User_;
	ConfigManager*		Config_;
	UiManager*			Ui_;
	StateManager*		State_;
	SystemManager*		System_;
	AudioManager*		Audio_;
	InputManager*		Input_;
	UWorld*				Scope_;
	UViewportClient*	Viewport_;
	ADisplayManager*	Display_;
	APlayerController*	Control_;
	
};
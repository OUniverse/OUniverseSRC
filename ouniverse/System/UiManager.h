//Copyright 2015-2019, All Rights Reserved.

/**

## UiManager

> **Singleton Service: Created once only by the boot process.**

The UiManager is a service singleton which manages all user interface elements (UI).

#### IO
IO is used here as an abbreviation for Interface Object and is any menu component
* A menu IO can be made up of many smaller IOs.

#### Tasks:
* Coordinates all of the UI's IO elements.
* Allows the IO elements to register with other systems (For example the console registering for the console CommandC).
* Activates each IO so that they bind themselves to the actual UI.
* Provides functions for other parts of the program to trigger UI events like popup notifications or data ribbons.

**Creator:** UBoot
**Holder:** Major

 */


#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "UiManager.generated.h"

class Io;
class UBoot;

class AchieveIO;
class AreaIO;
class ConsoleIO;
class ErrorIO;
class DataIO;
class IntroIO;
class MarkersIO;
class SystemMenuIO;
class NoticeIO;
class PopupIO;
class PulseIO;
class ToastIO;

class GlassC;


USTRUCT()
struct OUNIVERSE_API FUiGlyph
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FString ID;
	UPROPERTY()
	FString Graphic;
	UPROPERTY()
	FString Name;
	UPROPERTY()
	FString Description;
	UPROPERTY()
	FString Context;

	FUiGlyph()
	{
		ID = "$NL";
		Graphic = "$NL";
		Name = "$NL";
		Description = "$NL";
		Context = "$NL";
	}
};



class OUNIVERSE_API UiManager
{
	
	friend UBoot;

private:

	static UiManager* Create(GlassC* InGlass);
	UiManager(GlassC* InGlass);
	

public:

	GlassC* Glass_;


	enum IoTypes : uint8
	{
		Achieve,
		Area,
		Console,
		Error,
		Data,
		Intro,
		Markers,
		SystemMenu,
		Notice,
		Popup,
		Pulse,
		Toast,
		MAX,
	};

	AchieveIO* IoAchieve();
	AreaIO* IoArea();
	ConsoleIO* IoConsole();
	ErrorIO* IoError();
	DataIO* IoData();
	IntroIO* IoIntro();
	MarkersIO* IoMarkers();
	SystemMenuIO* IoSystemMenu();
	NoticeIO* IoNotice();
	PopupIO* IoPopup();
	PulseIO* IoPulse();
	ToastIO* IoToast();

private:

	AchieveIO* AchieveIOM;
	AreaIO* AreaIOM;
	ConsoleIO* ConsoleIOM;
	ErrorIO* ErrorIOM;
	DataIO* DataIOM;
	IntroIO* IntroIOM;
	MarkersIO* MarkersIOM;
	SystemMenuIO* SystemMenuIOM;
	NoticeIO* NoticeIOM;
	PopupIO* PopupIOM;
	PulseIO* PulseIOM;
	ToastIO* ToastIOM;

	std::vector <Io*> IoVector;

	void RegisterIO(IoTypes Type, Io* Io);
};

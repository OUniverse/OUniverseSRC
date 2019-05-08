//Copyright 2015-2019, All Rights Reserved.

/**
The UiManager is a Singleton extension to MAJOR (GameInstance) and manages User Interface elements (UI).

UiManager creates an object called IO (InterfaceObjects) for each feature of the UI.
For example, the notification popups or console are each an IO.
The IO handles the backend code which talks to the javascript front end of the UI. 
The goal is to keep as much of the backend functionality in the IO as possible.
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

class UCohtmlHUD;


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

	static UiManager* Create(UCohtmlHUD* InUi);
	UiManager(UCohtmlHUD* InUi);
	

public:

	UCohtmlHUD* Ui;


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

//Copyright 2015-2019, All Rights Reserved.

#include "System/UiManager.h"

#include "System/Paths.h"

#include "Ui/AchieveI.h"
#include "Ui/AreaI.h"
#include "Ui/ConsoleI.h"
#include "Ui/ErrorI.h"
#include "Ui/DataI.h"
#include "Ui/IntroI.h"
#include "Ui/MarkersI.h"
#include "Ui/SystemMenuI.h"
#include "Ui/NoticeI.h"
#include "Ui/PopupI.h"
#include "Ui/PulseI.h"
#include "Ui/ToastI.h"

#include "Misc/FileHelper.h"
#include "Json.h"

#include "System/InputManager.h"

#include "CohtmlHUD.h"
#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include "CohtmlFStringBinder.h"
#include "CohtmlUTypeBinder.h"

#include "Min/MajorM.h"

UiManager* UiManager::Create(UCohtmlHUD* InUi)
{
	return new UiManager(InUi);
}


UiManager::UiManager(UCohtmlHUD* InUi)
{
	MAJOR_IN_USAGE

	Ui = InUi;
	IoVector.assign(IoTypes::MAX, NULL);



	SystemMenuIOM = new SystemMenuIO(Ui);
	RegisterIO(IoTypes::SystemMenu, SystemMenuIOM);

	AchieveIOM = new AchieveIO(Ui);
	RegisterIO(IoTypes::Achieve, AchieveIOM);

	AreaIOM = new AreaIO(Ui);
	RegisterIO(IoTypes::Area, AreaIOM);

	ConsoleIOM = new ConsoleIO(Ui, MAJOR->Input());
	RegisterIO(IoTypes::Console, ConsoleIOM);

	ErrorIOM = new ErrorIO(Ui);
	RegisterIO(IoTypes::Error, ErrorIOM);

	DataIOM = new DataIO(Ui);
	RegisterIO(IoTypes::Data, DataIOM);

	IntroIOM = new IntroIO(Ui);
	RegisterIO(IoTypes::SystemMenu, IntroIOM);

	MarkersIOM = new MarkersIO(Ui);
	RegisterIO(IoTypes::Markers, MarkersIOM);

	NoticeIOM = new NoticeIO(Ui);
	RegisterIO(IoTypes::Notice, NoticeIOM);

	PopupIOM = new PopupIO(Ui);
	RegisterIO(IoTypes::Popup, PopupIOM);

	PulseIOM = new PulseIO(Ui);
	RegisterIO(IoTypes::Pulse, PulseIOM);

	ToastIOM = new ToastIO(Ui);
	RegisterIO(IoTypes::Toast, ToastIOM);


	SystemMenuIOM->Activate();
	ConsoleIOM->Activate();
	PulseIOM->Activate();
	PopupIOM->Activate();
	PulseIOM->AddPulse();
	AchieveIOM->Activate();
}

void UiManager::RegisterIO(IoTypes Type, Io* Io)
{
	IoVector[Type] = Io;
}

AchieveIO* UiManager::IoAchieve() { return AchieveIOM; };
AreaIO* UiManager::IoArea() { return AreaIOM; };
ConsoleIO* UiManager::IoConsole() { return ConsoleIOM; };
ErrorIO* UiManager::IoError() { return ErrorIOM; };
DataIO* UiManager::IoData() { return DataIOM; };
IntroIO* UiManager::IoIntro() { return IntroIOM; };
MarkersIO* UiManager::IoMarkers() { return MarkersIOM; };
SystemMenuIO* UiManager::IoSystemMenu() { return SystemMenuIOM; };
NoticeIO* UiManager::IoNotice() { return NoticeIOM; };
PopupIO* UiManager::IoPopup() { return PopupIOM; };
PulseIO* UiManager::IoPulse() { return PulseIOM; };
ToastIO* UiManager::IoToast() { return ToastIOM; };
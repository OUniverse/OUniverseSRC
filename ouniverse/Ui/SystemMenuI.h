//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
The MainMenu is the original out of game menu where the Player can select what USER ID they are along with many other settings.
Contains SubMenu IOs (IoM) which are in the Ui/MainMenu folder.
 */

#include "CoreMinimal.h"
#include "Ui/Io.h"
#include <vector>
#include <map>
#include "SystemMenuI.generated.h"

class UiManager;
class UCohtmlHUD;
class IoSM;

class CreationISM;
class CreditsISM;
class DataISM;
class DetailsISM;
class PlaythroughISM;
class NewsISM;
class SettingsISM;
class TitleISM;
class UserISM;


UCLASS()
class OUNIVERSE_API USystemMenuOption : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FString ID;
	UPROPERTY()
	FString Icon;
	UPROPERTY()
	FString SubIcon;
	UPROPERTY()
	FString Title;
	UPROPERTY()
	FString SubText;
	UPROPERTY()
	bool Lock;
	UPROPERTY()
	bool Hide;

	USystemMenuOption()
	{
		ID = "";
		Icon = "";
		SubIcon = "";
		Title = "";
		SubText = "";
		Lock = false;
		Hide = false;
	}
};


class OUNIVERSE_API SystemMenuIO : public Io
{
	friend UiManager;


public:

	void OnSubMenuConcluded();
	void OpenSubMenu(FString MenuID, FString OpenMode);

	
	enum SubMenus : uint8
	{
		Creation,
		Credits,
		Title,
		News,
		User,
		Playthrough,
		Data,
		Settings,
		Details,
		MAX,
	};

private:


	SystemMenuIO(UCohtmlHUD* InUi);

	bool bOverlayEnabled;

	TArray<USystemMenuOption*> Options;

	IoSM* ActiveMenu;
	SubMenus NextMode;
	SubMenus CurrentMode;


	std::map <FString, SubMenus> SubMenuStringMap;
	std::vector <IoSM*> SubMenuVector;

	void OnMenuClose(FString MenuID);

	
	void SetMenu(SubMenus NewMode);
	IoSM* GetMenu(SubMenus Menu);

	SubMenus GetMenuEnumFromString(FString ModeAsString);

	void Activate() override;
	void King() override;
	void EvaluateOptions();
	void SetOverlayEnabled(bool bEnable);
	

	CreationISM* CreationI;
	CreditsISM* CreaditsI;
	DataISM* DataI;
	DetailsISM* DetailsI;
	PlaythroughISM* PlaythroughI;
	NewsISM* NewsI;
	SettingsISM* SettingsI;
	TitleISM* TitleI;
	UserISM* UserI;

};
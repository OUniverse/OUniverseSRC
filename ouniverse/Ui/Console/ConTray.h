//Copyright 2015-2019, All Rights Reserved.



#pragma once

#include "Ui/UiAlpha.h"
#include "ConTray.generated.h"


class ConsolePro;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UConTray : public UUiAlpha
{

	GENERATED_BODY()

	friend ConsolePro;

private:
	
	virtual void NativeConstruct() override;

	static UConTray* Create(ConsolePro* InPro);
	void Init(ConsolePro* InPro);

private:

	ConsolePro* Profile_;

};
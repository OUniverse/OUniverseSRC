//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "Interface/Map.h"
#include "Protocol/Brass.h"

struct WriBrassS
{
	WriBrassS() {}

	WriBrassS(int InIcon, int InTitle, int InDescription)
	{
		Icon_ = InIcon;
		Title_ = InTitle;
		Description_ = InDescription;
	};

	int Icon_;
	int Title_;
	int Description_;
};


class UWriBrass;

class OUNIVERSE_API WriBrassP : public ProtocolC, public BrassC
{

public: 

	WriBrassP(int InID);

	void ConstructUi(UWriBrass* InView);

	UWriBrass* View_;

	void BrassDisplay(int BrassID) override;

	void BrassClear() override;

	MapC<int, WriBrassS> Lib_;

};
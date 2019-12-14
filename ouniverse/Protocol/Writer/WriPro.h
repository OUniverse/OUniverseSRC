//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "Protocol/Flux.h"
#include "System/Input.h"


class UUi;
class UMajor;
class MaestroC;

class WriMenuP;
class WriSplashP;

class UWriPro;

class FluxSwitchOpC;

class OUNIVERSE_API WriterPro : public ProtocolC, public InputStackC
{
	friend MaestroC;

public: 

	void GoMain();
	void EscWriter();

private:

	static WriterPro* Create(int InID, UMajor* InMajor);

	WriterPro(int InID, UMajor* InMajor);

	UMajor* Major_;
	MaestroC* Maestro_;
	UUi* Ui_;

	WriMenuP* WriMain_;
	WriSplashP* WriSplash_;
	UWriPro* View_;
	

	static enum Focus {
		FOCUS_MAX,
	};

	static enum Dock {
		DWri,
		DOCK_MAX,
	};
	
	static enum Pro {
		PSplash,
		PMain,
		PRO_MAX,
	};

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void OpenSplash();
};
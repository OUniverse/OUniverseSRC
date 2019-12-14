//Copyright 2015-2019, All Rights Reserved.


#pragma once

class FluxDockC;
struct FluxDataS;
class FluxC;
class ProtocolC;

class InputStackC;

class FluxOpC
{

public:

	virtual void Run() {};

protected:

	static enum Type {
		Switch,
	};

	
	FluxOpC(FluxOpC::Type InType);
};

class FluxSwitchOpC : public FluxOpC
{

public:

	static FluxSwitchOpC* Create(ProtocolC* InOwner, int DockID, int PendingID);

	FluxSwitchOpC(ProtocolC* InOwner, int DockID, int PendingID);

	void OpenComplete();

	void TransitionComplete();

	void CloseComplete();

	void Run() override;

	void DirectInputStack(InputStackC* InStack);

	void Ensure();

	void FocalSwap(int FocalID);

private:

	bool Ensure_;
	int FocalID_;

	int PendingID_;
	int DockID_;
	FluxDockC* Dock_;
	ProtocolC* Pending_;
	ProtocolC* Owner_;

	InputStackC* InputStack_;
};
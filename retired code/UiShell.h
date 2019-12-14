//Copyright 2015-2019, All Rights Reserved.


#pragma once

class UUiAlpha;
class ProtocolC;

class UiShellC
{

public:

	UiShellC(int InID, ProtocolC* InProtocol);

	virtual void Activate() {};

	void Deactivate();

	void SetAlpha(UUiAlpha* InAlpha);

	UUiAlpha* Alpha();

	int ID();

protected:

	virtual void SetProtocol() {};

	int ID_;
	ProtocolC* AbstractProtocol_;
	UUiAlpha* Alpha_;
};
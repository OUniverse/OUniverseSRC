//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiShell.h"


class SystemPro;
class UMajor;

class SymC : public UiShellC
{

public:

	SymC(int InID, SystemPro* InProtocol, UMajor* InMajor);

	void Activate() override;

	SystemPro* Protocol();

private:

	SystemPro* Protocol_;

	UMajor* Major_;
};
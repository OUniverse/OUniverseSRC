//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiShell.h"

class WriterPro;
class UMajor;

class WriC : public UiShellC
{

public:

	WriC(int InID, WriterPro* InProtocol, UMajor* InMajor);

	void Activate() override;

	WriterPro* Protocol();


protected:

	WriterPro* Protocol_;
	UMajor* Major_;
};
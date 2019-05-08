//Copyright 2015-2019, All Rights Reserved.

/**
Log Minimal
Wrapper around the LOG singleton.
- Intended access point to the logging system.
 */

#pragma once

#include "System/Log.h"

#define GEN 0
#define BOOT 1
#define HOT 2
#define LOG (type,verb,indent,text) OTLogger::Get()->Write(type,verb,indent,text)
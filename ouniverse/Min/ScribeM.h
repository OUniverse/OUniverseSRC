//Copyright 2015-2019, All Rights Reserved.

/**
Scribe Minimal
Wrapper around the Scribe singleton.
- Intended access point to the Scribe logging system.
 */

#pragma once

#include "System/Scribe.h"

#define SCRIBE(Code32,Aux) ScribeC::Get()->Write(Code32,Aux);

#define SCRIBEP ScribeC::Get()->Print();
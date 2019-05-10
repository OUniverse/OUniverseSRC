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
#define LOG(Type,Verb,Indent,Text) LogC::Get()->Write(Type,Verb,Indent,Text);
#define LOGP LogC::Get()->Print();
#define LOGD(Type,Verb,Indent,Text) LogC::Get()->Write(Type,Verb,Indent,Text);LogC::Get()->Print();

#if !defined IFS
#define IFS(InInt) FString::FromInt(InInt)
#define FFS(InFloat) FString::SanitizeFloat(InFloat)
#endif
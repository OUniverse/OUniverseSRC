//Copyright 2015-2019, All Rights Reserved.

/**
Macroed the UE4 HTTP request to get access to the templating of UE4's BindRaw.
This is kind of deep end so I figured it would be better to just trust in UE4 here in case they know some platform specific tricks / optimizations.
*/

#pragma once

#include "Runtime/Online/HTTP/Public/Http.h"

#define HTTP(url,obj,func) FHttpModule* Http = &FHttpModule::Get();TSharedRef<IHttpRequest> Request = Http->CreateRequest();Request->OnProcessRequestComplete().BindRaw(obj, func);Request->SetURL(url);Request->SetVerb("GET");Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");Request->SetHeader("Content-Type", TEXT("application/json"));Request->ProcessRequest();
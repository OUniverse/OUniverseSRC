//Copyright 2015-2019, All Rights Reserved.

#include "System/InternetManager.h"


InternetManager::InternetManager()
{
	bInternetConnection = false;
	bHandshakeValid = false;
	Http = &FHttpModule::Get();
	FString HandShakePath = "https://ouniverse.com/client/hs/ou1.hs";

	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	//Request->OnProcessRequestComplete().BindUObject(this, &InternetManager::OnVersionRequest);
	
	//Request->SetURL(HandShakePath);
	//Request->SetVerb("GET");
	//Request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	//Request->SetHeader("Content-Type", TEXT("application/json"));
	//Request->ProcessRequest();

	//LOG(LBOOT, 1, "InternetManager | Sending HandShake request: "+HandShakePath);
}

void InternetManager::OnVersionRequest(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{

	//LOG(LBOOT, 1, "InternetManager | HandShake request returned...");

	if (!bWasSuccessful)
	{
		//LOG(LBOOT, 1, "InternetManager | HandShake request: NO RESPONSE");
		//DEBUGPRINT(FColor::Green, "NO SITE");
	}
	else {
		bInternetConnection = true;
		FString HandShakeString = Response->GetContentAsString();
		
		if (HandShakeString.Left(3) == "OU1")
		{
			bHandshakeValid = true;
			HandShakeString = HandShakeString.RightChop(3);
			//LOG(LBOOT, 1, "InternetManager | HandShake is valid: " + HandShakeString);
		}
		else {
			//LOG(LBOOT, 1, "InternetManager | Handshake received but is not valid: "+ HandShakeString);
		}

		//DEBUGPRINT(FColor::Green, HandShakeString);
	}
	
}
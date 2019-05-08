//Copyright 2015-2019, All Rights Reserved.

/**
The InternetManager is a Singleton extension to MAJOR and manages internet connection settings.

Only does a few tasks:
- Check to see if there is an internet connection, 
- Checks to see if there is a more current version.
- If the News menu is visited it downloads the news display.
- Possibly will be used for keeping official atlases updated in the future.
*/

#pragma once


#include "Runtime/Online/HTTP/Public/Http.h"


class OUNIVERSE_API InternetManager 
{


public:

	InternetManager();
	bool bInternetConnection;
	bool bHandshakeValid;

	FHttpModule* Http;

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnVersionRequest(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

};


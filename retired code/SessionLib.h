//Copyright 2015-2019, All Rights Reserved.

/**

## SessionLib

Loadas all session files from a folder (A Session is similar to a playthrough)

#### Tasks:
* Can return a session from and ID if a match is found with a Session UID
* Manages the shifting of Sessions or assigning a new Session.
* Scans the session directory and creates a Session class object for each valid Session found.

**Creator:** KernelC
 
 */

#include "Interface/String.h"
#include "Interface/Array.h"

class SessionC;

class OUNIVERSE_API SessionLibC
{

	static const char* EXT;

public:

	SessionLibC(StringC InUserPath);

	static SessionLibC* Create(StringC InUserPath);

	int Num();

	bool Try(int InUID, SessionC*& OutSession);

	ArrayC<SessionC*> Sessions();

private:

	StringC Path_;

	int Num_;

	bool Loaded;

	ArrayC<SessionC*> SessionArray;

};
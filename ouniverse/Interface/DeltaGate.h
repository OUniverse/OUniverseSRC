//Copyright 2015-2019, All Rights Reserved.

/**

## Dir

**Struct:** DirS

Represents a directory in an OOP sense.

* Allows paths to be passed around and dynamically updated if changed.
* Has a few helper functions for directory management built in.

> Possibly this should be changed to a class.

*/

#pragma once

class DeltaGateC
{

public:
	DeltaGateC(float DeltaTime);
	DeltaGateC();

	bool Overflowed(float DelataTime);

protected:

	float Limit_;
	float Current_;

};
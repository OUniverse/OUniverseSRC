//Copyright 2015-2019, All Rights Reserved.

/**

## Data
> **Singleton Service: Created once only by the boot process.**

Data is a singleton which loads all the atlas style game data.

#### Tasks
* Creates and triggers a PayloadC which unpacks the entire atlas folder.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

class UBoot;
class PayloadC;
struct DirS;

class OUNIVERSE_API DataC
{
	friend UBoot;

private:

	static DataC* Create(DirS* InDirAtlas);
	
	DataC(DirS* InAtlasDir);
	
	PayloadC* Payload_;

	DirS* DirAtlas_;

public:

	static DataC* Get();
	DataC();

	void Scan();


};

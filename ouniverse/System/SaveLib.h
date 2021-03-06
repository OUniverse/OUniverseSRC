//Copyright 2015-2019, All Rights Reserved.

/**

## SaveLib

> **Singleton Service: Created once only by the boot process.**
>
A service singleton which manages all Save data. (A Save represents the person that is playing.)

#### Tasks:
* Can return Save from an ID or a serial number (In case ID is changed)
* Manages the shifting of Saves or assigning a new Save.
* Scans the Save directory and creates a SaveFolder class object for each valid Save found.

**Creator:** UBoot
**Holder:** Major
 
 */

#pragma once

#include "CoreMinimal.h"
#include "Interface/Array.h"
#include "Interface/String.h"
#include "Interface/Url.h"

class BootC;

class SaveDaisC;
class SaveC;
struct DirS;
class KernelC;

class OUNIVERSE_API SaveLibC
{

	friend BootC;

private:

	SaveLibC(SaveDaisC* InSaveW);

	~SaveLibC();

private:

	SaveDaisC* SaveDais_;

	ArrayC<SaveC*> Lib_;
	
	FolderC Folder_;

public:


	bool Try(int UID, SaveC*& InSave);
	
	void Set(int UID);

	void Add(SaveC* NewSave);
	
	void Load(FolderC InFolder);

	void Unload();

	ArrayC<SaveC*> Saves();

};
//Copyright 2015-2019, All Rights Reserved.

/**

## Cosmos
> **Singleton Service: Created once only by the boot process.**

Cosmos is a singleton service that acts like a 3D space bucket. All 3D space objects are loaded into and by the Cosmos.

#### Tasks
* Handles loading and unloading levels smoothly.
* Loads world style levels
* Loads effect style levels such as 3D effects used by menus.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

class BootC;
class SaveDaisC;

class OUNIVERSE_API SaveVatC
{

	friend BootC;

public:

	static SaveVatC* Create(SaveDaisC* InSaveDais);

	static SaveVatC* Get();

	SaveVatC();

	SaveVatC(SaveDaisC* InSaveDais);

	void Load();

private:

	SaveDaisC* SaveD_;
};
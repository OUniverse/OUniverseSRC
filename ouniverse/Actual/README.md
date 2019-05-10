# ACTUAL
**ACTUAL** classes closely mirror ***Form*** classes as they represent an instance of a *Form* class. In the example of an item such as a pair of boots: 

The boots would have their base stats such as weight, description and a pointer to the 3D model stored in the *Form* but if they are actually manifested in the world, as in being owned by a character or placed somewhere in the world, then an *Actual* is made which represents an instance of a *Form*.

### FORMULA

* All **Actual** classes are suffixed by the letter A. Example:
	* ActorA
	* RefA
* All **Actual** files are suffixed by the letter A. Example:
	* #include "Actual/ActorA.h
	* #include "Actual/RefA.h"
* **Actuals** all are part of a inheritance chain so that each step of the chain can handle the unpacking of their related data. Example:
	* ActorA >> ObjectA >> FormA

* Their final inheritance must be the base **FormA** class.

### BASE CLASS
* FormA
	
### UNIQUES
This folder has no unique oversight files. All of them currently are formulaic inheritance based *Actuals*.

### TODO
* Continue to refine and develop the functionality of all **Actuals** this is a large ongoing TODO as a majority of game features are held within these.
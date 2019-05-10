# FORM
**FORM** classes are marshal containers for loaded in Json data and function like schema in combination with their corresponding ***Actual*** file.

### FORMULA

* All **Form** classes are suffixed by the letter F. Example:
	* AbilityF
	* WeatherF
* All **Form** files are suffixed by the letter F. Example:
	* #include "Form/AbilityF.h
	* #include "Form/RefF.h"
* **Forms** all are part of a inheritance chain so that each step of the chain can handle the marshaling of their related data. Example:
	* ActorF >> ObjectF >> FormF

* Their final inheritance must be the base **FormF** class.

### BASE CLASS
* FormF
	
## UNIQUES

#### Atlas.h / Atlas.cpp
An Atlas is a proprietary semi json based data document which holds many forms. Very similar to a mod file.
* Parses Json to marshal itself from.
* Hands down Json data so that each inheritance level can marshal itself.
* Manages linking, injection, and overwriting of it's internal ***Forms***.
#### Payload.h / Payload.cpp
The base most class of loading in data 
* Loads all active ***Atlasi*** once selected by the ***User***.
*  Can reset the loading state of all such ***Atlasi*** and their internal ***Forms***. 
* Contains function pointers to creation factories for each type of data form so that the correct type is made.
* Does some secretarial work like tracking the total ***Atlas*** count and some optimizations around string pointers to names.
* Helps the ***SaveGame*** system interact with ***Forms***.
* Helps the ***Injection*** and ***Overwrite*** system modify ***Forms*** to enable multiple mods to impact the same data.
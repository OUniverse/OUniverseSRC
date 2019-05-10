
# Code Functionality Overview
This document is a summary of how the components of the source code function and how the project is organized.


## Data Driven
OUniverse is Data Driven and loads all of it's game content during the opening menus. It loads data from (mostly) JSON based text documents which function like mods. Which documents are used is semi configurable by the user through UI menus.

## Actual & Form
These 2 class types are the core elements of OUniverse's Data Driven system. Forms are base data and Actuals are instances made from the base data. To explain more in depth:

### Form
When the Data is loaded by OUniverse for each entry in the document a "Form" is created.  A Form is JSON marshaled into a C++ class. The Form classes use inheritance and all extend from a basic Form class. Their JSON data is handed down through their parents to clearly initialize themselves.

> **FORMS** link to other forms so in order to not have to store string based representation of links in instanced classes all Forms are unpacked first and assigned an ID before being Marshaled. This way all links only need a single pointer worth of storage to hold the address of the linked FORM.
> 
### Actual
**ACTUAL** classes closely mirror form classes. They represent an instance of a form. In the example of an item like a pair of boots: The boots  would have their base stats such as weight, description and a pointer to the 3D model stored in the **FORM** but if they are actually manifested in the world as in being owned by a character or placed somewhere in the world then an actual is made which represents an instance of a form.

## Folders

### ACTUAL
Holds all the **"ACTUAL"** classes used to make instances of  Forms.
* All ACTUAL classes are suffixed by the letter A.
*  Intended to extend other Actuals mirrored in their Form inheritance in an OOP style.
*  Their final inheritance must be the base Actual class. 
### FORM
Holds all the **FORM** classes which are marshal containers for loaded in Json data.
* All ACTUAL classes are suffixed by the letter A.
* All FORM classes are suffixed by the letter F.
*  Mirrors the "ACTUAL" files.
* Their final inheritance must be the base Form class.
### INTERFACE
Holds access to some broader / generic system. These classes are designed to function like wrappers so that they have their internals changed to other approaches / 3rd parties without breaking functionality.
* **File** is basic OS file system functionality like read, write, delete, and gather files or folders in directories.
* **Json** wraps around Json parsing functionality. The current implementation is using **rapidjson**. JSON writing is handled separately using  my our JsonWriter utility so that complex Temporary structs for marshaling are not needed.
### MATH
Any pure math structures or functions go here. 
### MIN
This project's style guide allows for Global Singleton instances to control services. The rule is that they are wrapped in a minified file which  holds macros to access their functionality. These minified files are what should be included to access the Global Singletons. This allows some swapping of functionality and provides a point for indirection while at least showing some information in the #includes on what Global Singletons are being used by a translation. 
> The style guide supports the usage of Global Singletons only when Dependency Injection can not elegantly solve a problem. If a service is being passed through to many unrelated things and there is no logical workaround then a Singleton may be accessed. 
### SECURE
Hidden files that should not be uploaded to public repos.
### SUPPORT
Currently just serving as a grab bag, most likely it will be removed.
### SYSTEM
Core systems and services and facilitators of the boot process. A majority of the major functionality of OUniverse is in here.
### UI
Each UI file is a sister script to a JavaScript object in the UI. They serve as a pathway to relay functionality to the C++. 
* Suffixed with either IO or I depending on circumstance.* ### UTIL
Various helper scripts that haven't found a clear home yet. 
### WORLD
A majority of these might to be moved to actual but for now serve to hold the OOP structure of Worlds, Regions and Areas.  
* Includes world feature management like **Populace** which manages the day by day routines of Actors or **Climate** which manages weather systems.

## Boot Process
OUniverse is set up by a procedeural boot script.
1. **UBoot::Boot** (in System/Boot.h) is called by the default UE4 level. It has a test variant also for unit testing isolated parts without having to comment out a lot of the boot process.
2. Boot sets up and configures most of the singletons.
3. **StateManager** is then given control which combined with the **UiManager** swap between the different interactive states of the program.
4. The user is allowed to set up their data via menu and once confirmed all the data is loaded into Forms.
5. The game is ready to start at this point.
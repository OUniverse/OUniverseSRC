# OUniverse C++ Style Guide

Style is chosen to be similar to Epic's UE4 style but not mimic it exactly so that it's clear which code is our own This helps distinguish what parts require garbage collection and UE4 Macro assignments.

### Principles
* Readability is greatly valued over speed of writing but meaningful performance gains is valued the most. 
* Increases compile time speed is valued if it doesn't involve to much confusion or breaking from the rules.

## Default
All classes and variables are named in a way that describes their purpose in an object sense. No special characters are used inside the name such as an underscore. The first letter of every word is capitalized.


* AtlasLibrary
* AudioGroup

## Member Variables
Suffixed with an underscore when the name collides with a Getter function

*Log_
*DataManager_

## Parameters
Uses In before the Parameter name:
```c++
WirteToLog(LogC* InLog)
{
Log_ = InLog;
}
```
## const vs Macro
Prefer using the Preproccessor over const to isolate efficiency measures from the code itself. 

## Class

Followed by the letter "C" if it's name will collide with it's logical parameter name. This unlocks the ability to use Capitals similar to Epic but differentiating by using a signifying suffix instead of a prefix. Personally my eye can read these at a glance much quicker with a suffixed letter as opposed to a prefix.

* class LogC
* LogC*
* PopulaceEngineC

Struct-like classes with abstract names can be simply named as they are but could use an S prefix as well:
* ColorRBG
* JsonWriter
* VersionS


#### Specialty Cases
Certain repetitive purpose classes can have their own suffix. For example States are prefixed with T and UI element interfaces are followed by I.

* OpenWorldS
* SystemMenuS
* InventoryI
* DialogueI

## Macros
All upper case only used for efficiency purposes and as wrappers around Singletons.

## Templates
Not used except for UE4's 

## Nested Classes and Structs
Used if they really have no usage outside of their placement and are not very complex. Primarily with structs that are data containers.
## Virtual
Anywhere inheritance is needed for the desired functionality.
## Operator Overrides
Used only if the functionality is very obvious and the code gains enough cuteness to warrant it.
## Patterns

#### Injection
Greatly prefer injection anytime the code can be elegantly presented as a logical tree of objects and components. 

#### Global Variables
Simple global variables on their own are not used however globally accessible singleton instances are used sparingly in specific situations.

#### Singleton

It's our belief that game development requires some exceptions from OOP injection principles. A majority of it works perfectly with OOP however certain things do wind up having to reach far across the scope of the program no matter what. To allow more complex and interesting features we opt into minimal usage of singletons through a service locator designated **Major**. 

> The log also is a singleton but with it's own access outside of the service locator.

A second aspect favoring global usage in a limited capacity is the boot initialization process which requires loading many data documents that are parsed. For performance reasons in certain cases it very much appears ideal to load and hold onto the needed data in a singleton-esque fashion.

Code however that can suit Injection should always prefer it and on the flip side dependencies being passed without use through many scopes will be implemented as singletons if there's no further clear logical upgrades for the code structure to suit an elegant injection.

#### Singleton Rules
* Singletons can be implemented as classes that have private static Get() and Create() functions and the class is friended to the UBoot script and any procedeural testing script only.
* Singletons come with a an additional header file which serves as a Minified access point for other classes to access it. 
##### Singleton's Minified Header

* The "Minimal" header matches the Singleton's class header's file name but is suffixed with a **M**. It has the Get() function wrapped in a Marcro #define and in certain cases like logging has additional macros to access certain logs:


```c++
#define GENERAL 0
#define BOOT 1
#define HOT 1

#define LOG (type,verb,indent,text) LogC::Get()->Write(type,verb,indent,text)
```

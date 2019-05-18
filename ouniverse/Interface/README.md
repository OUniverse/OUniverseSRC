# INTERFACE
The goal is to include as much core interface functionality into carefully planned Interface wrappers. This will benefit speed of working and having proprietary reusable classes that accomplish what we need now and into the future. When dealing with an engine and 3rd parties there are a sometimes inevitable conversions (IE: UE4's FString) so having full control of automated conversions saves a lot of time.

## Array

**Class:** ArrayC

Generic array implementation.
> Wrapper around a std::vector

## Dir

**Struct:** DirS

Represents a directory in an OOP sense.

* Allows paths to be passed around and dynamically updated if changed.
* Has a few helper functions for directory management built in.

> Possibly this should be changed to a class.

## DirQuery

**Struct:** DirQueryS

Functionality for querying directories within a directory.

* Can return the name all folders within a directory.
* Can return the full path of all folders within a diretory.
* Can return the number of folders in a directory.

## Event

**Class:** Event0C / Listener0C
**Class:** Event1C / Listener1C
**Class:** Event2C / Listener2C

Specialized event delegates interface.

* Registerable event which methods can sign up for.
* Uses a tokenesque sign up so that registry can be canceled from the token itself
* Gather fires events and gets return values
* Trigger fires events and ignores return values
* Can register multiple methods

#### Macros

Typedefs the Event and the Listener for easy use.

* EVENT0 (EventType,ListenerType,ReturnVar)
* EVENT1 (EventType,ListenerType,ReturnVar,Param1)
* EVENT2 (EventType,ListenerType,ReturnVar,Param1,Param2)

## File
**Class:**  FileC
Custom OOP File class with some helper functionality.

## FileQuery

**Struct:** FileQueryS

Functionality for querying files within a directory.

* Can return the name all files within a directory.
* Can return the full path of all files within a diretory.
* Can return the number of files in a directory.
* Can filter by extension.
* Check if file exists.

## Gemini

**Class:**  GeminiC

A commonly used pairing of int + int as a dual map key representing the Atlas ID + Form ID.
This was converted to an interface due to it's core functionality in OUniverse's Data/Atlas strategy.

* Represents a map of a map both with int keys which returns a form.

> Might be changed to return an atlas which then has it's own map.

## HashMap

**Class:**  HashMapC

Not yet implemented, will be a wrapper around a std::unordered_map.


## Increment

**Struct:**  IncrementS

Self contained incrementing INT with a cursor to the next available number for dealing unique ID values.

## Ini

**Class:**  IniC

Loads and saves ini documents from a path.

#### Features
* Can restore any value to default.
* Only writes altered values.
* Access values by exact type.

#### Additions
**Entry:**  Abstract Ini Entry.
**String:**  Entry extension which contains a StringC.
**Float:**  Entry extension which contains a float.
**Int:**  Entry extension which contains an int.
**Bool:**  Entry extension which contains a bool.

## Json

**Struct:**  JsonS

Json reader only interface which is a wrapper around rapidjson

## JsonWriter

**Struct:**  JsonWriterS

Custom JSON serializer for fast minimal output without having to create marshal structs.

## Map

**Class:** MapC

Generic map implementation.
> Wrapper around a std::map

## String

**Class:** StringC

Generic string implementation.
> Wrapper around a std::string with some custom functionality.

## Thread

**Class:** ThreadC

No interface needed since std::thread is so straightforward.
Currently just a static function for detecting hardware max thread.

## Twin

**Struct:** TwinS

Commonly used storage system by the Atlas/Form data system of OUniverse..
Holds a pair of int64s.


## Void

**Struct:** Void

For templates when a void can not be used as a return value this custom Void can be used.
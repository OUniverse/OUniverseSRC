

# INTERFACE
The goal is to include as much core interface functionality into carefully planned Interface wrappers. This will benefit speed of working and having proprietary reusable classes that accomplish what we need now and into the future. When dealing with an engine and 3rd parties there are a sometimes inevitable conversions (IE: UE4's FString) so having full control of automated conversions saves a lot of time.

## String
Custom string interface

## Dir
Custom OOP Folder (Directory) class.

## File
Custom OOP File class.

## Array
Currently a wrapper around a **std::vector**.

* **Init (Amount, Default)**
* **Add (NewType)**
* **operator[Index]** Returns the value at Index.
* **+=** ***NewType***   Adds to the Array via std:;vector.push_back
* **Len**  Gets the size of the Array
  
## Map
Currently a wrapper around a **std::map**.

* **Add (NewKey , NewType)**
* **Find (KeyName)**'
* **Try (KeyName , REF)** Returns true/false if it finds something with the key and sets REF to what it finds.
* **contains(Key)** true/false if it has the key.
* **operator[KeyName]** Returns value paired with KeyName
* **Len**  Gets the size of the Array
* **IsEmpty**  true/false if empty
* **At(Index)**  Sorts the map in order and gets an index, used for iterating through all entries in the Map. 
> Map.At(Index) might be a really messy implementation but I couldn't figure out a better way to do this for now.

## HashMap
** INCOMPLETE **
Currently a wrapper around a std::unordered_map

## Delegate
**REMOVED**
Originally was a wrapper around a *Infinitely Fast Delegate* but the documentation on usage was too thin when dealing with them in Events template style and my brain almost exploded writing the Template for an Event Handler that uses a nested custom Listener class. Some performance benchmarks were showing that std::function is about the same speed so it's unclear for now without further testing if it really matters. 

> If there comes a time when  committing to *infinitely fast* makes sense we can use the interface wrapper to swap them out.
> 
## Event

Custom templated code I wrote using an EventListener (EventC) and a Listener (ListenerC). 

#### Gather()
Makes the EventListener gather return values from all it's listeners.
#### Trigger()
Fires all the Listener delegates and ignores their return values.

The inner Listener class serves a few purposes:
* Aids in easily registering and binding to the interface
* Is a easy to use handle to unregister or adjust the delegate
* Allows for custom flags to be set, like if it should be a thread or if it should unregister itself on use.

## Ini

Fairly complex ini interface for retrieving pointers to variables (so they reflect changes when checked). These return the exact expected types so no casting is required.

#### TODO

##### OnChange:
Might add events to the ini or create inherited ones that have events so that OnChange events can be registered for.
##### Lang:
Translation files will use something similar to INIs but are only expected to have strings ever, so a lighter weight ini might be created that only handles IO of strings.

## Json
An interface for reading JSON data that currently is a wrapper around **rapidjson**.

## Void
Events are struggling returning a void so a requirement for delegates is that functions used by the Event interface must returning something not void. Initially I was returning and int as 0 but this was confusing in some cases in knowing if the return value is actually important or just a placeholder for void. Void is intended to communicate that the function's return value is not important.
# SYSTEMS

## AudioGroups

AudioGroups are nesting volume control containers Example: Voice/UI/Music/Ambience.
* These are intended to be adjustable by the user from ingame menus during gameplay.

**Creator:** AudioManager
**Holder:** AudioManager

## AudioManager
> **Singleton Service: Created once only by the boot process.**

A service singleton which manages audio settings and handles playback.
* Created once in the boot process.

**Creator:** UBoot
**Holder:** Major

## Boot

Boot is the procedeural process of setting up all of OUniverse's services and allowing them to load their data and set each other up.
> Boot works by calling the UBoot::Boot function from any level in UE4 blueprints.

Tasks:
* Creates the Major singleton and adds all services to it.
	* The Major singleton is friended with Boot so that it can only be manipulated by the boot process.
	* Later it might be friend to some testing classes also to allow controlled testing of many components.
* Upon completing this task it hands things off to the ProtocolManager.
* Has alternate boot calls like BootTest() to give quick access to controlled tests.

## CharKey
CharKey are command relays of certain presses while in typing mode using CHAR style input. 
* Instead of sending the Char as a code it sends commands for special keys such as Backspace, Escape, Delete etc.

**Creator:** InputManager
**Holder:** InputManager
**Related:** CommandC


## Commands
Every action triggered by input in OUniverse has a Command associated with. (For example "Jump" "Accept" "Interact" are all Commands.).
Commands forward receipt of the input action via Event Delegates which can be registered for.
These Event Delegates broadcast all clicks and presses to all registered methods.

#### Tasks
* Allows other areas of the program to easily register for Command Events.
* Commands are stored on a Map keyed by KeyScanCodes so they can be easily remapped.

**Creator:** InputManager
**Holder:** InputManager
**Related:** CharKeyC

## ConfigManager

> **Singleton Service: Created once only by the boot process.**

A service singleton which loads the configuration ini files at boot and stores them for use throughout the lifetime.

**Additionals:**
**IniKey:** Namespace control over an enum system for each possible ini entry.

**Creator:** UBoot
**Holder:** Major

## ControlUE

AControlUE is an exension to UE4's APlayerController.

> Currently does nothing as the SInputCatch and InputManager are doing most of it's responsibilities.


## Cosmos
> **Singleton Service: Created once only by the boot process.**

Cosmos is a singleton service that acts like a 3D space bucket. All 3D space objects are loaded into and by the Cosmos.

#### Tasks
* Handles loading and unloading levels smoothly.
* Loads world style levels
* Loads effect style levels such as 3D effects used by menus.

**Creator:** UBoot
**Holder:** Major


## Data
> **Singleton Service: Created once only by the boot process.**

Data is a singleton which loads all the atlas style game data.

#### Tasks
* Creates and triggers a PayloadC which unpacks the entire atlas folder.

**Creator:** UBoot
**Holder:** Major

## Glass

Glass is a bridge / interface wrapper between the UI and the game code.
* Created once in the boot process.

> Currently it's a bridge between C++ to Coherent Labs UI system and is interacting with Javascript there.

**Creator:** AHudUE Outputs this to UBoot
**Holder:** Major

## GraphicsManager

> **Singleton Service: Created once only by the boot process.**

A service singleton which stores global graphics settings for use throughout the lifetime.

**Creator:** UBoot
**Holder:** Major

## AControlUE

AControlUE is an exension to UE4's AHud.

The Coherent Lab's Ui solution extends this.
This is an extension of Coherent Lab's extension for further control.

#### Tasks
* Sets up the primary UI overlay.
* Outputs a UI bridge singleton to access all of Coherent Lab's functionality.
* 
## InputCatch

A full screen blank widget which gathers all input events.
Upon receiving the interactions it forwards them to the InputManager to handle the press/click.

**This is a bandaid to get around the shortcomings of UE4's control system.**

#### Benefits:
* Easy access to rebinding.
* Full control over what keypresses and inputs are doing.
* Distinction between Char Typing and Input commands.
* Allows for a more OOP approach to controls.
* 
## InputManager

> **Singleton Service: Created once only by the boot process.**

A service singleton the manages all input events.
Receives all inputs like keyboard and mouse interactions from the SInputCatch widget.

#### CommandArray
- Creates all the input Commands used by the game by setting up a class with Event Delegates inside.
- Command's event delegates can be registered for.
- Creates a ENUM based map for easy access by the C++ code and also a keycode map to convert key presses to commands
- The keycode map allows for easy rebinding as well.

#### CharKeyArray
- Same as CommandArray but handles Char Key presses while in typing mode.

**Creator:** UBoot
**Holder:** Major

## Log

Logging class, primarily intended to be created once by the boot process and used as a singleton.
> Here it's created once at startup by the boot script but can be instanced if needed.

**Creator:** UBoot
**Holder:** Major

## Major
> **Service Locator: Created once only by the boot process.**

> **Accessed through a Minimal Macro Wrapper MajorM.**

A service locator singleton that holds the pointers to all the services.

*Major will be sparingly dropped in locations where Dependency Injection is causing too much pressure and not logically feeling great. Generally if parameters are being passed around only to hand off with no relevance to the receiver it will be omitted from injection and retrieved when needed from Major.*

**Creator:** UBoot
**Holder:** GlobalSingletons namespace as a global var

## Mode

Extends UE4's AGameMode and holds default game mode assignments.

#### Current Swaps:
* APlayerController to AControLUE 
* AHud to AHudUE

## Paths
> **Singleton Service: Created once only by the boot process.**

A service singleton extension that precomputes and stores required directory paths through out the lifetime.

#### Tasks:
- Precomputes paths so they only need to be string assembled once.
- Generates pointer wrapers to directories so that changes to directory during lifetime are reflected in realtime without any monitoring or events.

**Creator:** UBoot
**Holder:** Major

## Server

> **Singleton Service: Created once only by the boot process.**

A service singleton which provides a layer between input and action.

* This is dabbling in the potential for some remote multiplayer by having a gathering spot for inputs and actions.
* Ideally this can be used to allow a second player to join the game by having both players receiving outcomes from
	this server code running on the initial player's computer.

**Creator:** Not Implemented (Will be Boot)
**Holder:** Not Implemented (Will be Major)

## Services

This is basically Major and should be removed.

## StateManager

> **Singleton Service: Created once only by the boot process.**

A service singleton that handle the logic of different modes the game can be in.

An example of different states would be the System Menu compared to Open World. The usage in either state is significantly different from each other.

#### Tasks
* Loads the State subclasses like a cartridge to run which change the logic.
* Handles the loading and unloading of States.
* Synchronizes a change in States by ensuring an old one is unloaded before loading in a new one.

**Creator:** UBoot
**Holder:** Major

## SystemManager

> **Singleton Service: Created once only by the boot process.**

The SystemManager is a service singleton which scans devices and gathers knowledge it needs for performance of the user's system.
This data is held onto for the lifetime so it only needs to be recorded once at startup.

**Creator:** UBoot
**Holder:** Major

## Terra

> **Singleton Service: Created once only by the boot process.**

A service singleton which handles worlds, universes, zones etc in an OOP style.

#### Tasks:
* Calculates the activities of citizens, the weather, and world events.
* Unpacks the form data for what objects should be placed in the 3D world.
* Does not spawn the 3D world itself but communicates with CosmosC to output the world.

**Creator:** UBoot
**Holder:** Major

## UiManager

> **Singleton Service: Created once only by the boot process.**

The UiManager is a service singleton which manages all user interface elements (UI).

#### IO
IO is used here as an abbreviation for Interface Object and is any menu component
* A menu IO can be made up of many smaller IOs.

#### Tasks:
* Coordinates all of the UI's IO elements.
* Allows the IO elements to register with other systems (For example the console registering for the console CommandC).
* Activates each IO so that they bind themselves to the actual UI.
* Provides functions for other parts of the program to trigger UI events like popup notifications or data ribbons.

**Creator:** UBoot
**Holder:** Major


## UserFolder

A User Folder is a marshaling of the results of scanning a folder in the user directory.

**Creator:** UserLib
**Holder:** UserLib

## UserLib

> **Singleton Service: Created once only by the boot process.**
> 
A service singleton which manages all User data. (A User represents the person that is playing.)

#### Tasks:
* Can return user from an ID or a serial number (In case ID is changed)
* Manages the shifting of Users or assigning a new User.
* Scans the user directory and creates a UserFolder class object for each valid user found.

**Creator:** UBoot
**Holder:** Major

## Version
Static constant access to version information of the program.

> Will most likely require access functions to pull versioning info from the UI and from UE4.

## AViewportUE

An extension to UE4's AViewport.

The program required access to window focus lost or received and this was the only way.

**Warning:**  *UE4 already uses Init as a function in Viewport so it can't be used.*
**Warning:** *If this code is related to a crash it's because this custom viewport got unset as the viewport to use in the UE4 editor settings.*
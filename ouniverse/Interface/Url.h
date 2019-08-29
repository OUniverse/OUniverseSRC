//Copyright 2015-2019, All Rights Reserved.

/**

## Dir

**Struct:** DirS

Represents a directory in an OOP sense.

* Allows paths to be passed around and dynamically updated if changed.
* Has a few helper functions for directory management built in.

> Possibly this should be changed to a class.

*/

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"

class NewFileC;
class NewFolderC;
class DocC;
class DocStreamC;


class NewFolderC
{

public:
	NewFolderC();
	NewFolderC(StringC InPath);

	void Make();

	StringC ToString();

	NewFileC ToFile(StringC File, StringC Ext);

	StringC GetFinalDir();

	ArrayC<NewFolderC> GetFolders();
	ArrayC<NewFileC> GetFiles();
	ArrayC<NewFileC> GetFiles(StringC InExtension);


protected:

	StringC S_;

};


class NewFileC
{

public:

	NewFileC();

	NewFileC(NewFolderC InFolder, StringC InFileName, StringC InExtension);

	StringC ToString();

	DocC Doc();

	bool Exists();

private:

	NewFolderC Fo_;
	StringC Fi_;
	StringC Ext_;
};


class DocC
{

public:

	DocC(NewFileC InFile);

	DocC& Open();

	bool Success();

	NewFileC ToFile();

	bool Append(StringC Text);
	bool Write(StringC Text);
	bool Empty();

	StringC ToString();

private:
	
	NewFileC F_;
	StringC S_;

	bool Success_;
};


class PathC
{
public:

	static NewFolderC DirLog();
	static NewFolderC DirUsers();
	static NewFolderC DirConfig();
	static NewFolderC DirAtlas();
	static NewFileC FileLog();
	static NewFileC FileGlobalConfig();

	static void SetGlobals();
};
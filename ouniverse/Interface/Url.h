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

class UrlC
{

public:

	UrlC(StringC InPath);

	void Make();

	bool IsFile();
	bool IsFolder();

	const char* ToChar();
	operator StringC() const;

	NewFileC ToFile();
	NewFolderC ToFolder();

	void operator=(StringC In);

protected:

	StringC S_;
};

class NewFileC
{

public:

	NewFileC();

	NewFileC(StringC InPath);
	
	const char* ToChar();
	StringC ToString();

	DocC Doc();

	DocStreamC Stream();

	bool Exists();

protected:

	StringC S_;
};

class NewFolderC
{

public:
	NewFolderC();
	NewFolderC(StringC InPath);

	void Make();

	const char* ToChar();
	StringC ToString();

	static NewFolderC DirLog();
protected:

	StringC S_;

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
	const char* ToChar();

private:
	
	NewFileC F_;
	StringC S_;

	bool Success_;
};

class DocStreamC
{

public:

	DocStreamC(NewFileC InFile);

private:

	NewFileC F_;

};

class PathC
{
public:

	static void SetGlobals();
};
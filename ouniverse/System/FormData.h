//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once


class FormF;
class AtlasC;

class UWriForm_ScrollEntry;
class UWriForm_Port;

class FormDataC
{

public:

	FormDataC() {};
	FormDataC(AtlasC* InAtlas, FormF* InForm);

	AtlasC* Atlas();
	FormF* Form();
	
	void SetOpen(bool status);

private:

	AtlasC* Atlas_;
	FormF* Form_;
	
	bool Open_;
	bool Unsaved_;
	bool Error_;

	UWriForm_ScrollEntry* Entry_;
	UWriForm_Port* Port_;
};
//Copyright 2015-2019, All Rights Reserved.


#pragma once


class ProvenanceC
{

public:

	ProvenanceC();
	ProvenanceC(int InWriter ,int InDoc);

	bool IsCurrent();
	bool IsValid();

private:

	int Writer_;
	int Doc_;
};
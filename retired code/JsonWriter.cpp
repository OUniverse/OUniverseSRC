//Copyright 2015-2019, All Rights Reserved.

#include "Interface/JsonWriter.h"



void JsonWriterS::Add(StringC Key, int Val)
{
	J = J+"\""+Key+"\":"+Val+",";
}


void JsonWriterS::Add(StringC Key, StringC Val)
{
	J = J+"\""+Key+"\":"+"\""+Val+"\",";
}

void JsonWriterS::Object(StringC Key)
{
	Obj++;
	J = J +"\""+Key+"\":"+"{";
}

void JsonWriterS::BaseObject()
{
	Obj++;
	J+="{";
}

void JsonWriterS::EndObject()
{
	Obj--;
	J = J.RemoveLastChar()+"}";
}


void JsonWriterS::BaseArray()
{
	Obj++;
	J += "{";
}


void JsonWriterS::Array(StringC Key)
{
	Arr++;
	J = J+"\""+Key+"\":"+"[";
}

void JsonWriterS::EndArray()
{
	Arr--;
	J.RemoveLastChar();
	J+="]";
}

StringC JsonWriterS::Print()
{
	return J;
}
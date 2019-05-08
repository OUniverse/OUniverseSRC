//Copyright 2015-2019, All Rights Reserved.

#include <Form/Ref.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

RefF::RefF(){}
FormF* RefF::Create() { return new RefF(); }
void RefF::Marshal(rapidjson::Document* J)
{
	FormF::Marshal(J);
}
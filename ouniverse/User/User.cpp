//Copyright 2015-2019, All Rights Reserved.

#include "User/User.h"
#include "User/DeclarationU.h"


UserC::UserC(DeclarationU* InDeclaration)
{
	Declaration_ = InDeclaration;
	Files.Add(Declaration_);
}
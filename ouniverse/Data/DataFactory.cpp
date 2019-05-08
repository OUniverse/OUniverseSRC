//Copyright 2015-2019, All Rights Reserved.

#include "Data/DataFactory.h"
#include "Data/Data.h"

Data* DataFactory::Create() { return new Data(); }
Data* F_Data::Create() { return new Data(); }
Data* F_Ref::Create() { return new D_Ref(); }
Data* F_Actra::Create() { return new D_Actra(); }
Data* F_Area::Create() { return new D_Area(); }
Data* F_Static::Create() { return new D_Static(); }
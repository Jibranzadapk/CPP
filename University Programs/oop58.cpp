//It allows a namespace to be used in several header files, 
//which can then all be included in a source file.

//fileA.h
namespace alpha
{
	void funcA();
}

//fileB.h
namespace alpha
{
	void funcB();
}

//fileMain.cpp

#include “fileA.h”
#include “fileB.h”
using namespace alpha;
funcA();
funcB();

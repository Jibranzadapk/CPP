// chap 13 starts
#include <iostream>

using namespace std; 

//Defining a Namespace
//Code outside a namespace cannot access the elements within it
//The namespace makes them invisible:
	
namespace geo
{
	const double PI = 3.14159;

	double circumf(double radius)
	{ return 2 * PI * radius; }
} //end namespace geo
//using namespace geo;
//double c = circumf(10); //won’t work here

//There are two ways to do this

double c = geo::circumf(10); //OK

//Or you can use the using directive:
using namespace geo;
//The using directive ordinarily causes the namespace to be visible from that point onward.

int main(){
	
	double d = circumf(10); //OK
	cout<<d;	
	return 0;
}

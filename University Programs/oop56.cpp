//you can restrict the region where the using directive is in effect to a particular block,
//such as a function:

namespace geo
{
	const double PI = 3.14159;

	double circumf(double radius)
	{ return 2 * PI * radius; }
} //end namespace geo

using namespace geo;

void seriousCalcs()
{
	using namespace geo;
	//other code here
	double c = circumf(10); //OK
}
void sum(){
	
	double d=PI*2;
}
//double c = circumf(10); //not OK

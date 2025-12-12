//Multiple Namespace Definitions

namespace geo
{
	const double PI = 3.14159;
} // end namespace geo

//(some other code here)
namespace geo
{
	double circumf(double radius)
	{	
	return 2 * PI * radius; 
	}
} //end namespace geo

using namespace geo;

int main(){
	
	double d = circumf(10); //OK
	
	return 0;
}

//This looks like a redefinition, but it’s really just a continuation 
//of the same definition

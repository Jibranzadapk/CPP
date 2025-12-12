//operator overloading
// increment counter variable with ++ operator

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class Counter
{
	private:
		unsigned int count; //count
	public:
		Counter() : count(0) //constructor
		{ }
		
		unsigned int get_count() //return count
		{ return count; }
		
		Counter operator ++ () //increment count
		{	
			++count; //increment count
			
			Counter temp; //make a temporary Counter
			temp.count = count; //give it same value as this obj
			
			return temp; //return the copy
		}
};

////////////////////////////////////////////////////////////////
int main()
{
	Counter c1, c2; //define and initialize

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

	//c1++; //increment c1

	++c2; //increment c2
	++c2; //increment c2

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

	c1 = ++c2;	

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

	return 0;
}

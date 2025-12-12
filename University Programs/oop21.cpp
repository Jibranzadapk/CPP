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
		Counter() : count(0) //constructor no args
		{ }

		Counter(int c) : count(c) //constructor, one arg
		{ }

		unsigned int get_count() //return count
		{ return count; }

		Counter operator ++ () //increment count
		{
			++count; // increment count, then return
			return Counter(count); // an unnamed temporary object
		} 							// initialized to this count

		
		Counter operator ++ (int) //increment count (postfix)
		{ 							//return an unnamed temporary
			return Counter(count++); //object initialized to this
		} 								//count, then increment count
};		

/*
This int isn’t really an argument, and it doesn’t mean integer. 
It’s simply a signal to the compiler to create the postfix version of the
operator. The designers of C++ are fond of doing such abnormalities
*/

////////////////////////////////////////////////////////////////
int main()
{
	Counter c1, c2; //define and initialize

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

	++c1; //increment c1

	++c2; //increment c2
	++c2; //increment c2

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

	c1= ++c2;	
	
	c1= c2++;
	
		

	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();

	return 0;
}

// object represents a counter variable
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter
{
	private:
		unsigned int count; //count
	public:
		Counter() : count(0) //constructor
		{ /*empty body*/ }

		void inc_count() //increment count
		{ count = count+5; }

		int get_count() //return count
		{ 
		cout<<"hello";
		return count; 
		}
};
	////////////////////////////////////////////////////////////////
int main()
{
	
	Counter c1, c2; //define and initialize
//	cout << "count="<<count<<endl;
	
	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count();
	c1.inc_count(); //increment c1

	for (int i=0; i<100; i++)
		c2.inc_count(); //increment c2
	
	cout << "\n\n\nc1=" << c1.get_count(); //display again
	cout << "\nc2=" << c2.get_count();
	cout << endl;
	return 0;
}

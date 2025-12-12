//Uses of Static Class Data

#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////

class foo674 ^
{
	private:
	//static 
	int count; //only one data item for all objects
	//note: “declaration” only!

	public:
	foo() : count(0)//increments count when object created
	{ count++; }

	int getcount() //returns count
	{ return count; }
	
	void setCount(int i){
		count += i;
	}
};

//--------------------------------------------------------------
//int foo::count = 0; //*definition* of count
////////////////////////////////////////////////////////////////

int main()
{
	foo f1, f2, f3; //create three objects
	
	 f1.setCount(10) ; //each object
	 f2.setCount(20) ; //each object
	 f3.setCount(30) ; //each object
	
	cout << "count is " << f1.getcount() << endl; //each object
	cout << "count is " << f2.getcount() << endl; //sees the
	cout << "count is " << f3.getcount() << endl; //same value
	return 0;
}


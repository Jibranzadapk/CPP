
// function template 

#include <iostream>
using namespace std;
//--------------------------------------------------------------

template <class apple> //function template

apple abs(apple n)
{
	return (n < 0) ? -n : n;
}
//--------------------------------------------------------------
int main()
{
	int int1 = 5;
	int int2 = -6;

	long lon1 = 70000L;
	long lon2 = -80000L;

	double dub1 = 9.95;
	double dub2 = -10.15;
	//calls instantiate functions

	cout << abs(int1)<< endl; //abs(int)
	cout << abs(int2)<< endl; //abs(int)
	
	cout << abs(lon1)<< endl; //abs(long)
	cout << abs(lon2)<< endl; //abs(long)
	
	cout << abs(dub1)<< endl; //abs(double)
	cout << abs(dub2)<< endl; //abs(double)
	cout << endl;
	
	return 0;
}



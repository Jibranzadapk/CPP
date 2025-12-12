// friend functions
// to avoid problems of multi inheritance

//controversial.
// against info hiding principle of OOP

//to fix the probllem it has been enforced that the prototype of friend function
//must be placed inside class body so that if a programmer does not have 
//access to the source code for the class he cannot make a function into a friend.

//friend functions should be used sparingly

// We want the function frifunc() to have access to both of these private data members, 
// It's declared with the friend keyword in both classes:

//This declaration can be placed anywhere in the class; 
// it doesn't matter whether it goes in the public or the private section

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class beta; //Remember that a class can't be referred to until it has been declared

class alpha
{
	private:
	int data;

	public:

	alpha() : data(3) 
	{ } //no-arg constructor

	friend int frifunc(alpha, beta); //friend function
	//must be declared within the class whose data it will access
};

////////////////////////////////////////////////////////////////
class beta
{
	private:
	int data;

	public:

	beta() : data(7) 
	{ } //no-arg constructor
	//
	//friend int frifunc(alpha, beta); //friend function
	//must be declared within the class whose data it will access
};

////////////////////////////////////////////////////////////////
int frifunc(alpha a, beta b) //function definition
{
	return( a.data + a.data );
}

//--------------------------------------------------------------
int main()
{
	alpha aa;
	beta bb;

	cout << frifunc(aa, bb) << endl; //call the function

	return 0;
}

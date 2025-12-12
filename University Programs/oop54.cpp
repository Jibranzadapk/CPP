// demonstrates typeid() function
// RTTI must be enabled in compiler

//chaptrer 11 completed. Assignment 3 announcement
// q 1 to 10 book page 561-566

#include <iostream>
#include <typeinfo> //for typeid()
using namespace std;

////////////////////////////////////////////////////////////////
class Base
{
	virtual void virtFunc() //needed for typeid
	{ }
};

class Derv1 : public Base
{ };

class Derv2 : public Base
{ };

////////////////////////////////////////////////////////////////
void displayName(Base* pB)
{
	cout << "pointer to an object of "; //display name of class
	cout << typeid(*pB).name() << endl; //pointed to by pB
}

//--------------------------------------------------------------
int main()
{
	Base* pBase;
	pBase = new Derv1;
	displayName(pBase); //”pointer to an object of class Derv1”

	pBase = new Derv2;
	displayName(pBase);
	
	pBase = new Base;
	displayName(pBase);
	 //”pointer to an object of class Derv2”

	return 0;
}
